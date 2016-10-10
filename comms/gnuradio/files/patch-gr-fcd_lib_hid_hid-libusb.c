--- gr-fcd/lib/hid/hid-libusb.c.orig	2015-04-13 14:32:43 UTC
+++ gr-fcd/lib/hid/hid-libusb.c
@@ -250,8 +250,8 @@ static int get_usage(uint8_t *report_des
 }
 #endif /* INVASIVE_GET_USAGE */
 
-#ifdef __FreeBSD__
-/* The FreeBSD version of libusb doesn't have this funciton. In mainline
+#ifndef HAVE_LIBUSB_GET_STRING_DESCRIPTOR
+/* The FreeBSD version of libusb doesn't have this function. In mainline
    libusb, it's inlined in libusb.h. This function will bear a striking
    resemblence to that one, because there's about one way to code it.
 
@@ -756,8 +756,12 @@ static void *read_thread(void *param)
 	   if no transfers are pending, but that's OK. */
 	libusb_cancel_transfer(dev->transfer);
 
+#if 0
 	while (!dev->cancelled)
 		libusb_handle_events_completed(usb_context, &dev->cancelled);
+#endif
+	while (!dev->cancelled)
+		libusb_handle_events(NULL);
 
 	/* Now that the read thread is stopping, Wake any threads which are
 	   waiting on data (in hid_read_timeout()). Do this under a mutex to
