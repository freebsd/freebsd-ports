--- src/mba/shellout.h.orig	Tue May 18 18:07:17 2004
+++ src/mba/shellout.h	Mon Feb 21 01:54:34 2005
@@ -9,6 +9,7 @@
 #endif
 
 #include <termios.h>
+#include <unistd.h>
 
 #define SHO_FLAGS_INTERACT 0x0001
 #define SHO_FLAGS_ISATTY   0x0100
