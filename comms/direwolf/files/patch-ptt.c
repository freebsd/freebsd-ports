--- ptt.c.orig	2018-10-08 14:15:21 UTC
+++ ptt.c
@@ -139,7 +139,7 @@
 
 #if __WIN32__
 #else
-#include <sys/termios.h>
+#include <termios.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
 #include <sys/types.h>
