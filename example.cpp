#include <BU9873.h>

BU9873 rtc;

void setup() {
    Serial.begin(115200);
    rtc.begin(21, 22); // สมมติใช้ GPIO21 SDA, GPIO22 SCL

    BU9873::rtc_time_t now;
    if (rtc.getTime(now)) {
        Serial.printf("Time: %02d:%02d:%02d %02d/%02d/20%02d\n",
                      now.hours, now.minutes, now.seconds,
                      now.day, now.month, now.year);
    } else {
        Serial.println("Failed to read time");
    }

    // ตัวอย่างตั้งเวลา
    // BU9873::rtc_time_t settime = {30, 15, 12, 2, 23, 4, 25}; // 12:15:30 Tuesday, 23 April 2025
    // rtc.setTime(settime);
}

void loop() {
    delay(1000);
}
