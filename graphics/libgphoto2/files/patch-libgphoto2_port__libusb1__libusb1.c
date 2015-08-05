--- libgphoto2_port/libusb1/libusb1.c.orig	2015-06-15 20:13:54 UTC
+++ libgphoto2_port/libusb1/libusb1.c
@@ -66,6 +66,10 @@
 	}\
 } while(0)
 
+#ifndef LIBUSB_CALL
+#define LIBUSB_CALL
+#endif
+
 #ifndef HAVE_LIBUSB_STRERROR
 static const char *libusb_strerror(int r)
 {
