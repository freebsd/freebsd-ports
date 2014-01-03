--- libusb/hid.c.orig
+++ libusb/hid.c
@@ -25,6 +25,8 @@
 
 #define _GNU_SOURCE /* needed for wcsdup() before glibc 2.10 */
 
+#include <config.h>
+
 /* C */
 #include <stdio.h>
 #include <string.h>
@@ -250,7 +252,7 @@
 }
 #endif /* INVASIVE_GET_USAGE */
 
-#ifdef __FreeBSD__
+#if ! HAVE_DECL_LIBUSB_GET_STRING_DESCRIPTOR
 /* The FreeBSD version of libusb doesn't have this funciton. In mainline
    libusb, it's inlined in libusb.h. This function will bear a striking
    resemblence to that one, because there's about one way to code it.
@@ -324,6 +326,7 @@
 static wchar_t *get_usb_string(libusb_device_handle *dev, uint8_t idx)
 {
 	char buf[512];
+	char buf2[512];
 	int len;
 	wchar_t *str = NULL;
 	wchar_t wbuf[256];
@@ -359,7 +362,7 @@
 	   it is only passed into iconv() which does not need it. */
 
 	/* Initialize iconv. */
-	ic = iconv_open("WCHAR_T", "UTF-16LE");
+	ic = iconv_open("char", "UTF-16LE");
 	if (ic == (iconv_t)-1) {
 		LOG("iconv_open() failed\n");
 		return NULL;
@@ -369,18 +372,21 @@
 	   Skip the first character (2-bytes). */
 	inptr = buf+2;
 	inbytes = len-2;
-	outptr = (char*) wbuf;
-	outbytes = sizeof(wbuf);
+	outptr = buf2;
+	outbytes = sizeof(buf2);
 	res = iconv(ic, &inptr, &inbytes, &outptr, &outbytes);
 	if (res == (size_t)-1) {
 		LOG("iconv() failed\n");
 		goto err;
 	}
+	res = mbstowcs(wbuf, buf2, sizeof(wbuf)/sizeof(wbuf[0]));
+	if (res == (size_t)-1) {
+		LOG("mbstowcs() failed\n");
+		goto err;
+	}
 
 	/* Write the terminating NULL. */
 	wbuf[sizeof(wbuf)/sizeof(wbuf[0])-1] = 0x00000000;
-	if (outbytes >= sizeof(wbuf[0]))
-		*((wchar_t*)outptr) = 0x00000000;
 
 	/* Allocate and copy the string. */
 	str = wcsdup(wbuf);
@@ -757,7 +763,7 @@
 	libusb_cancel_transfer(dev->transfer);
 
 	while (!dev->cancelled)
-		libusb_handle_events_completed(usb_context, &dev->cancelled);
+		libusb_handle_events(usb_context);
 
 	/* Now that the read thread is stopping, Wake any threads which are
 	   waiting on data (in hid_read_timeout()). Do this under a mutex to
