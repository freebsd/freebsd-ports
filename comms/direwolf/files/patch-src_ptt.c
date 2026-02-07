--- src/ptt.c.orig	2021-12-17 15:05:52 UTC
+++ src/ptt.c
@@ -148,7 +148,7 @@
 
 #if __WIN32__
 #else
-#include <sys/termios.h>
+#include <termios.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
 #include <sys/types.h>
