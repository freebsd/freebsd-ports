--- righandling/dabstick-2/librtlsdr.c.orig
+++ righandling/dabstick-2/librtlsdr.c
@@ -29,7 +29,11 @@
 
 #define lmin(a, b) (((a) < (b)) ? (a) : (b))
 //#include <libusb.h>
+#ifdef __FreeBSD__
+#include	<libusb.h>
+#else
 #include	"libusb-1.0/libusb.h"
+#endif
 
 
 /*
