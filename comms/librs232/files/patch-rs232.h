--- rs232.h.orig	2014-12-04 14:17:08.000000000 +0800
+++ rs232.h	2014-12-04 14:17:22.000000000 +0800
@@ -45,8 +45,7 @@
 #include <string.h>
 
 
-
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 
 #include <termios.h>
 #include <sys/ioctl.h>
