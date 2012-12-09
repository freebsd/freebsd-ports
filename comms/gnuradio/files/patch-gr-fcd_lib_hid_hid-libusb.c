--- gr-fcd/lib/hid/hid-libusb.c.orig	2012-09-27 14:50:40.000000000 -0500
+++ gr-fcd/lib/hid/hid-libusb.c	2012-09-27 15:45:03.000000000 -0500
@@ -48,6 +48,12 @@
 
 #include "hidapi.h"
 
+#ifdef __FreeBSD__
+#define LIBUSB_GET_STRING_DESCRIPTOR(h,i,l,d,n)	libusb_get_string_descriptor_ascii(h,i,d,n)
+#else
+#define LIBUSB_GET_STRING_DESCRIPTOR(h,i,l,d,n)	libusb_get_string_descriptor(h,i,l,d,n)
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
@@ -264,7 +270,7 @@
 	int len;
 
 	/* Get the string from libusb. */
-	len = libusb_get_string_descriptor(dev,
+	len = LIBUSB_GET_STRING_DESCRIPTOR(dev,
 			0x0, /* String ID */
 			0x0, /* Language */
 			(unsigned char*)buf,
@@ -282,7 +288,7 @@
 	int i;
 
 	/* Get the string from libusb. */
-	len = libusb_get_string_descriptor(dev,
+	len = LIBUSB_GET_STRING_DESCRIPTOR(dev,
 			0x0, /* String ID */
 			0x0, /* Language */
 			(unsigned char*)buf,
@@ -327,7 +333,7 @@
 		lang = get_first_language(dev);
 
 	/* Get the string from libusb. */
-	len = libusb_get_string_descriptor(dev,
+	len = LIBUSB_GET_STRING_DESCRIPTOR(dev,
 			idx,
 			lang,
 			(unsigned char*)buf,
