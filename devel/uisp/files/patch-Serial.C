diff -urN Serial.C.orig Serial.C
--- Serial.C.orig	Tue Aug 29 17:08:28 2000
+++ Serial.C	Fri Feb 16 19:33:18 2001
@@ -10,7 +10,11 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
+#if defined (__FreeBSD__)
+#include <termios.h>
+#else
 #include <termio.h>
+#endif
 #include <fcntl.h>
 #include "Global.h"
 #include "Serial.h"
