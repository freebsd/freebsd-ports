--- libusb/hid.c.orig	2013-10-06 22:43:37 UTC
+++ libusb/hid.c
@@ -25,6 +25,8 @@
 
 #define _GNU_SOURCE /* needed for wcsdup() before glibc 2.10 */
 
+#include <config.h>
+
 /* C */
 #include <stdio.h>
 #include <string.h>
@@ -250,7 +252,7 @@ static int get_usage(uint8_t *report_des
 }
 #endif /* INVASIVE_GET_USAGE */
 
-#ifdef __FreeBSD__
+#if ! HAVE_DECL_LIBUSB_GET_STRING_DESCRIPTOR
 /* The FreeBSD version of libusb doesn't have this funciton. In mainline
    libusb, it's inlined in libusb.h. This function will bear a striking
    resemblence to that one, because there's about one way to code it.
@@ -333,11 +335,7 @@ static wchar_t *get_usb_string(libusb_de
 	size_t inbytes;
 	size_t outbytes;
 	size_t res;
-#ifdef __FreeBSD__
-	const char *inptr;
-#else
-	char *inptr;
-#endif
+	ICONV_CONST char *inptr;
 	char *outptr;
 
 	/* Determine which language to use. */
@@ -757,7 +755,11 @@ static void *read_thread(void *param)
 	libusb_cancel_transfer(dev->transfer);
 
 	while (!dev->cancelled)
+#if HAVE_DECL_LIBUSB_HANDLE_EVENTS_COMPLETED
 		libusb_handle_events_completed(usb_context, &dev->cancelled);
+#else
+		libusb_handle_events(usb_context);
+#endif
 
 	/* Now that the read thread is stopping, Wake any threads which are
 	   waiting on data (in hid_read_timeout()). Do this under a mutex to
