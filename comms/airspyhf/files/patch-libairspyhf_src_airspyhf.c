--- libairspyhf/src/airspyhf.c.orig	2026-07-22 12:39:48 UTC
+++ libairspyhf/src/airspyhf.c
@@ -1346,7 +1346,7 @@ int ADDCALL airspyhf_stop(airspyhf_device_t* device)
 	result2 = kill_io_threads(device);
 
 #ifndef _WIN32
-	libusb_interrupt_event_handler(device->usb_context);
+	// libusb_interrupt_event_handler(device->usb_context);
 #endif
 
 	if (result2 != AIRSPYHF_SUCCESS)
