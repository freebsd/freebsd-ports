libusb_has_capability() was implemented in r361977 and is only available on:
FreeBSD >= 1104501, 1201518, 1300098
However, libusb in all supported versions of FreeBSD supports hotplug events.

This patch can be safely removed after 11.4 and 12.1 EOL.

--- src/usb.c.orig	2021-01-21 10:10:40 UTC
+++ src/usb.c
@@ -815,7 +815,7 @@ int usb_init(void)
 	collection_init(&device_list);
 
 #ifdef HAVE_LIBUSB_HOTPLUG_API
-	if (libusb_has_capability(LIBUSB_CAP_HAS_HOTPLUG)) {
+	if (1) {
 		usbmuxd_log(LL_INFO, "Registering for libusb hotplug events");
 		res = libusb_hotplug_register_callback(NULL, LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED | LIBUSB_HOTPLUG_EVENT_DEVICE_LEFT, LIBUSB_HOTPLUG_ENUMERATE, VID_APPLE, LIBUSB_HOTPLUG_MATCH_ANY, 0, usb_hotplug_cb, NULL, &usb_hotplug_cb_handle);
 		if (res == LIBUSB_SUCCESS) {
