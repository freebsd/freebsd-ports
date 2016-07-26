--- lib/hidapi-0.8.0-pre/linux/hid-libusb.c.orig	2013-05-08 23:20:26 UTC
+++ lib/hidapi-0.8.0-pre/linux/hid-libusb.c
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
@@ -264,7 +270,7 @@ static uint16_t get_first_language(libus
 	int len;
 	
 	/* Get the string from libusb. */
-	len = libusb_get_string_descriptor(dev,
+	len = LIBUSB_GET_STRING_DESCRIPTOR(dev,
 			0x0, /* String ID */
 			0x0, /* Language */
 			(unsigned char*)buf,
@@ -282,7 +288,7 @@ static int is_language_supported(libusb_
 	int i;
 	
 	/* Get the string from libusb. */
-	len = libusb_get_string_descriptor(dev,
+	len = LIBUSB_GET_STRING_DESCRIPTOR(dev,
 			0x0, /* String ID */
 			0x0, /* Language */
 			(unsigned char*)buf,
@@ -327,7 +333,7 @@ static wchar_t *get_usb_string(libusb_de
 		lang = get_first_language(dev);
 		
 	/* Get the string from libusb. */
-	len = libusb_get_string_descriptor(dev,
+	len = LIBUSB_GET_STRING_DESCRIPTOR(dev,
 			idx,
 			lang,
 			(unsigned char*)buf,
