#ifndef Thermal_h
#define Thermal_h

#define PRINTER_PRINT(a) _printer->write(a);
#define SERIAL_IMPL Stream

class Adafruit_Thermal : public Print {

 public:

  Adafruit_Thermal();

  void
    begin(SERIAL_IMPL* serial, int heatTime=200),
    reset(),
    setDefault(),

    normal(),

    feed(uint8_t x=1),
    feedRows(uint8_t),
    flush(),
    online(),
    offline(),
    sleep(),
    sleepAfter(uint8_t seconds),
    wake(),
    listen(),

    printBitmap(int w, int h, const uint8_t *bitmap, bool fromProgMem = true),
    printBitmap(int w, int h, Stream *stream),
    printBitmap(Stream *stream),

    timeoutSet(unsigned long),
    timeoutWait(),
    setTimes(unsigned long, unsigned long),
    setMaxChunkHeight(int val);

  size_t write(uint8_t c);

 protected:

  SERIAL_IMPL
    *_printer;
  uint8_t
    prevByte,      // Last character issued to printer
    column,        // Last horizontal column printed
    maxColumn,     // Page width (output 'wraps' at this point)
    charHeight,    // Height of characters, in 'dots'
    lineSpacing,   // Inter-line spacing (not line height), in dots
    barcodeHeight; // Barcode height in dots, not including text
  unsigned long
    resumeTime,    // Wait until micros() exceeds this before sending byte
    dotPrintTime,  // Time to print a single dot line, in microseconds
    dotFeedTime;   // Time to feed a single dot line, in microseconds
  int
    printMode,
    maxChunkHeight;
  void
    setPrintMode(uint8_t mask),
    unsetPrintMode(uint8_t mask),
    writePrintMode(),
    writeBytes(uint8_t a),
    writeBytes(uint8_t a, uint8_t b),
    writeBytes(uint8_t a, uint8_t b, uint8_t c),
    writeBytes(uint8_t a, uint8_t b, uint8_t c, uint8_t d);
};

#endif // Thermal_h

