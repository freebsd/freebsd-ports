--- library/tulip/include/tulip/ConsoleUtils.h.orig	2012-02-24 08:48:00.000000000 +0100
+++ library/tulip/include/tulip/ConsoleUtils.h	2012-02-24 11:18:11.000000000 +0100
@@ -31,7 +31,7 @@
 #include <io.h>
 #endif
 
-#if defined(__linux) || defined(__APPLE__)
+#if defined(__linux) || defined(__APPLE__) || defined(__FreeBSD__)
 
 #include <termios.h>
 #include <sys/ioctl.h>
