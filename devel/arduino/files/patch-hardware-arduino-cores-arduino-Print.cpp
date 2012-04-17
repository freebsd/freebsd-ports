--- hardware/arduino/cores/arduino/Print.cpp.orig	2012-03-16 11:16:23.000000000 -0700
+++ hardware/arduino/cores/arduino/Print.cpp	2012-03-16 11:17:17.000000000 -0700
@@ -41,7 +41,7 @@
 
 size_t Print::print(const __FlashStringHelper *ifsh)
 {
-  const prog_char *p = (const prog_char *)ifsh;
+  const char PROGMEM *p = (const char PROGMEM *)ifsh;
   size_t n = 0;
   while (1) {
     unsigned char c = pgm_read_byte(p++);
--- patch-hardware-arduino-cores-arduino-Print.cpp ends here ---