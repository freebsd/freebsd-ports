--- libairspyhf/src/airspyhf.c.orig	2022-06-23 21:14:46 UTC
+++ libairspyhf/src/airspyhf.c
@@ -1189,7 +1189,7 @@ int ADDCALL airspyhf_stop(airspyhf_device_t* device)
 	int result1, result2;
 	result1 = kill_io_threads(device);
 	result2 = airspyhf_set_receiver_mode(device, RECEIVER_MODE_OFF);
-	libusb_interrupt_event_handler(device->usb_context);
+	// libusb_interrupt_event_handler(device->usb_context);
 
 	if (result2 != AIRSPYHF_SUCCESS)
 	{
