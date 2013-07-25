--- righandling/pmsdr/pmsdr_usb.h.orig
+++ righandling/pmsdr/pmsdr_usb.h
@@ -36,7 +36,11 @@
 //#ifdef __MINGW32__
 //#include	<libusb.h>
 //#else
+#ifdef __FreeBSD__
+#include	<libusb.h>
+#else
 #include	<libusb-1.0/libusb.h>
+#endif
 //#endif
 
 class	RadioInterface;
