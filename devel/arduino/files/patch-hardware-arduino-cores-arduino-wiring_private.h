--- hardware/arduino/cores/arduino/wiring_private.h.orig	2011-03-21 15:18:00.000000000 +0800
+++ hardware/arduino/cores/arduino/wiring_private.h	2011-03-21 15:18:13.000000000 +0800
@@ -27,7 +27,7 @@
 
 #include <avr/io.h>
 #include <avr/interrupt.h>
-#include <avr/delay.h>
+#include <util/delay.h>
 #include <stdio.h>
 #include <stdarg.h>
 
