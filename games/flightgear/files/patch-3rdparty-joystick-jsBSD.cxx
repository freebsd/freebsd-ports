--- 3rdparty/joystick/jsBSD.cxx.orig	2020-05-28 21:56:43 UTC
+++ 3rdparty/joystick/jsBSD.cxx
@@ -52,6 +52,7 @@
 #include <sys/param.h>
 #include <fcntl.h>
 
+#include <unistd.h>
 #include <string.h>
 #include <errno.h>
 #include <sys/ioctl.h>
