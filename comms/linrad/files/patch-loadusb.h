--- loadusb.h.orig	2014-12-08 03:09:37.000000000 -0800
+++ loadusb.h	2014-12-08 03:10:07.000000000 -0800
@@ -30,6 +30,7 @@
 
 #if OSNUM == OSNUM_LINUX
 #include <limits.h>
+#include <sys/time.h>
 #define LIBUSB_CALL
 #endif
 
