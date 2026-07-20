--- src/misc/SDL_libusb.c.orig	2026-07-01 16:20:42 UTC
+++ src/misc/SDL_libusb.c
@@ -92,7 +92,7 @@ bool SDL_InitLibUSB(SDL_LibUSBContext **ctx)
             LOAD_LIBUSB_SYMBOL(int (LIBUSB_CALL *)(libusb_context *, int *), handle_events_completed)
             LOAD_LIBUSB_SYMBOL(void (LIBUSB_CALL *)(libusb_context *ctx), interrupt_event_handler)
             LOAD_LIBUSB_SYMBOL(int (LIBUSB_CALL *)(uint32_t), has_capability)
-            LOAD_LIBUSB_SYMBOL(int (LIBUSB_CALL *)(libusb_context *, int, int, int, int, int, libusb_hotplug_callback_fn, void *, libusb_hotplug_callback_handle *), hotplug_register_callback)
+            LOAD_LIBUSB_SYMBOL(int (LIBUSB_CALL *)(libusb_context *, libusb_hotplug_event, libusb_hotplug_flag, int, int, int, libusb_hotplug_callback_fn, void *, libusb_hotplug_callback_handle *), hotplug_register_callback)
             LOAD_LIBUSB_SYMBOL(void (LIBUSB_CALL *)(libusb_context *, libusb_hotplug_callback_handle), hotplug_deregister_callback)
             LOAD_LIBUSB_SYMBOL(const char * (LIBUSB_CALL *)(int), error_name)
 #undef LOAD_LIBUSB_SYMBOL
