$FreeBSD$

--- IRremoteInt.h.orig	2009-09-05 23:55:48.000000000 -0700
+++ IRremoteInt.h	2011-12-27 15:40:59.000000000 -0800
@@ -12,12 +12,16 @@
 #ifndef IRremoteint_h
 #define IRremoteint_h
 
+#if defined(ARDUINO) && ARDUINO >= 100
+#include <Arduino.h>
+#else
 #include <WProgram.h>
+#endif
 
 #define CLKFUDGE 5      // fudge factor for clock interrupt overhead
 #define CLK 256      // max value for clock (timer 2)
 #define PRESCALE 8      // timer2 clock prescale
-#define SYSCLOCK 16000000  // main Arduino clock
+#define SYSCLOCK F_CPU  // main Arduino clock
 #define CLKSPERUSEC (SYSCLOCK/PRESCALE/1000000)   // timer clocks per microsecond
 
 #define ERR 0
