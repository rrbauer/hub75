// RGBW cycler for HUB75 panels, to measure current draw
// Written by Robert Bauer
// Fully public domain, do what you want with it, no attribution required

#include <RGBmatrixPanel.h>

// Most of the signal pins are configurable, but the CLK pin has some
// special constraints.  On 8-bit AVR boards it must be on PORTB...
// Pin 8 works on the Arduino Uno & compatibles (e.g. Adafruit Metro),
// Pin 11 works on the Arduino Mega.  On 32-bit SAMD boards it must be
// on the same PORT as the RGB data pins (D2-D7)...
// Pin 8 works on the Adafruit Metro M0 or Arduino Zero,
// Pin A4 works on the Adafruit Metro M4 (if using the Adafruit RGB
// Matrix Shield, cut trace between CLK pads and run a wire to A4).

#define CLK  8   // USE THIS ON ARDUINO UNO, ADAFRUIT METRO M0, etc.
//#define CLK A4 // USE THIS ON METRO M4 (not M0)
//#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2

#define ONVALUE 1

#define RGB_RED ONVALUE, 0, 0
#define RGB_GREEN 0, ONVALUE, 0
#define RGB_BLUE 0, 0, ONVALUE
#define RGB_WHITE ONVALUE, ONVALUE, ONVALUE
#define RGB_BLACK 0, 0, 0

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

void setup() {

  matrix.begin();

}

void loop() {

  long shortdelay = 1000;
  long delayms = 4000;

  // draw a pixel in white
  matrix.fillRect(0, 0, 32, 16, matrix.Color333(RGB_BLACK));
  matrix.drawPixel(0, 0, matrix.Color333(RGB_WHITE));
  delay(shortdelay);

  // fix the screen with black
  matrix.fillRect(0, 0, 32, 16, matrix.Color333(RGB_BLACK));
  delay(delayms);

  // fix the screen with red
  matrix.fillRect(0, 0, 32, 16, matrix.Color333(RGB_RED));
  delay(delayms);

 // fix the screen with green
  matrix.fillRect(0, 0, 32, 16, matrix.Color333(RGB_GREEN));
  delay(delayms);

 // fix the screen with blue
  matrix.fillRect(0, 0, 32, 16, matrix.Color333(RGB_BLUE));
  delay(delayms);

  // fill the screen with white
  matrix.fillScreen(matrix.Color333(RGB_WHITE));
  delay(delayms);

  // whew!
}
