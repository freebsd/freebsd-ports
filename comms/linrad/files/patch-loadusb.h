--- loadusb.h.orig	2014-11-04 10:25:00 UTC
+++ loadusb.h
@@ -30,6 +30,7 @@
 
 #if OSNUM == OSNUM_LINUX
 #include <limits.h>
+#include <sys/time.h>
 #define LIBUSB_CALL
 #endif
 
