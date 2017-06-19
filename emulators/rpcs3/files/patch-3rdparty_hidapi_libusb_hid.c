--- 3rdparty/hidapi/libusb/hid.c.orig	2017-04-29 01:03:27 UTC
+++ 3rdparty/hidapi/libusb/hid.c
@@ -397,7 +397,7 @@ static wchar_t *get_usb_string(libusb_device_handle *d
 	size_t inbytes;
 	size_t outbytes;
 	size_t res;
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) && __FreeBSD__ < 10
 	const char *inptr;
 #else
 	char *inptr;
