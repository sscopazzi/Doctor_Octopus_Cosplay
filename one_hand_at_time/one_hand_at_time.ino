#include <Wire.h>
//# include <Servo.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  850 //850 This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  1450 //1650 This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

// HAND ONE, HEADERS 0-3
uint8_t hand1_finger1  = 0;
uint8_t hand1_finger2  = 1;
uint8_t hand1_finger3  = 2;
//uint8_t hand1_cont = 3;

// HAND TWO, HEADERS 4-7
uint8_t hand2_finger1  = 4;
uint8_t hand2_finger2  = 5;
uint8_t hand2_finger3  = 6;
//uint8_t hand2_cont = 7;

// HAND THREE, HEADERS 8-11
uint8_t hand3_finger1  = 8;
uint8_t hand3_finger2  = 9;
uint8_t hand3_finger3  = 10;
//uint8_t hand3_cont = 11;

// HAND FOUR, HEADERS 12-15
uint8_t hand4_finger1  = 12;
uint8_t hand4_finger2  = 13;
uint8_t hand4_finger3  = 14;
//uint8_t hand4_cont = 15;

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

// CONT SERVOS - SPIN THE HANDS
// still need to figure out two spinning backwards
//  pwm.setPWM(hand1_cont, 0, 298); // 302 is the lowest speed the cont servos will spin at 
//  pwm.setPWM(hand2_cont, 0, 298);
//  pwm.setPWM(hand3_cont, 0, 298);
//  pwm.setPWM(hand4_cont, 0, 298);
  
  delay(10);
}

void loop() {
  Serial.println("Hand 1 Bottom Right IN");
  for (uint16_t microsec = USMIN; microsec < USMAX; microsec++) {
    pwm.writeMicroseconds(hand1_finger1, microsec);
    pwm.writeMicroseconds(hand1_finger2, microsec);
    pwm.writeMicroseconds(hand1_finger3, microsec);
//    pwm.writeMicroseconds(hand4_finger1, microsec);
  }
  Serial.println("Hand 2 Bottom Left IN");
  for (uint16_t microsec = USMIN; microsec < USMAX; microsec++) {
    pwm.writeMicroseconds(hand2_finger1, microsec);
    pwm.writeMicroseconds(hand2_finger2, microsec);
    pwm.writeMicroseconds(hand2_finger3, microsec);
//        pwm.writeMicroseconds(hand4_finger2, microsec);
  }
  Serial.println("Hand3 Top Right IN");
  for (uint16_t microsec = USMIN; microsec < USMAX; microsec++) {
    pwm.writeMicroseconds(hand3_finger1, microsec);
    pwm.writeMicroseconds(hand3_finger2, microsec);
    pwm.writeMicroseconds(hand3_finger3, microsec);
//        pwm.writeMicroseconds(hand4_finger3, microsec);
  }
  Serial.println("Hand4 Top Left IN");
  for (uint16_t microsec = USMIN; microsec < USMAX; microsec++) {
    pwm.writeMicroseconds(hand4_finger1, microsec);
    pwm.writeMicroseconds(hand4_finger2, microsec);
    pwm.writeMicroseconds(hand4_finger3, microsec);
//        pwm.writeMicroseconds(hand4_finger3, microsec);
  }

delay(200);
////////////////////////////
////////////////////////////  

  Serial.println("Hand 1 Bottom Right OUT");
  for (uint16_t microsec = USMAX; microsec > USMIN; microsec--) {
    pwm.writeMicroseconds(hand1_finger1, microsec);
    pwm.writeMicroseconds(hand1_finger2, microsec);
    pwm.writeMicroseconds(hand1_finger3, microsec);
//        pwm.writeMicroseconds(hand4_finger1, microsec);
  }
//
  Serial.println("Hand 2 Bottom Left OUT");
  for (uint16_t microsec = USMAX; microsec > USMIN; microsec--) {
    pwm.writeMicroseconds(hand2_finger1, microsec);
    pwm.writeMicroseconds(hand2_finger2, microsec);
    pwm.writeMicroseconds(hand2_finger3, microsec);
//        pwm.writeMicroseconds(hand4_finger2, microsec);
  }
//
  Serial.println("Hand 3 Top Left OUT");
  for (uint16_t microsec = USMAX; microsec > USMIN; microsec--) {
    pwm.writeMicroseconds(hand3_finger1, microsec);
    pwm.writeMicroseconds(hand3_finger2, microsec);
    pwm.writeMicroseconds(hand3_finger3, microsec);
//        pwm.writeMicroseconds(hand4_finger3, microsec);
  }
  Serial.println("Hand 4 Top Right OUT");
  for (uint16_t microsec = USMAX; microsec > USMIN; microsec--) {
    pwm.writeMicroseconds(hand4_finger1, microsec);
    pwm.writeMicroseconds(hand4_finger2, microsec);
    pwm.writeMicroseconds(hand4_finger3, microsec);
//        pwm.writeMicroseconds(hand4_finger3, microsec);
  }
  delay(200);
}
