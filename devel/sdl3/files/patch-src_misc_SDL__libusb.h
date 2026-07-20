--- src/misc/SDL_libusb.h.orig	2026-07-01 16:20:42 UTC
+++ src/misc/SDL_libusb.h
@@ -93,7 +93,7 @@ typedef struct SDL_LibUSBContext
     int (LIBUSB_CALL *handle_events_completed)(libusb_context *ctx, int *completed);
     void (LIBUSB_CALL *interrupt_event_handler)(libusb_context *ctx);
     int (LIBUSB_CALL *has_capability)(uint32_t capability);
-    int (LIBUSB_CALL *hotplug_register_callback)(libusb_context *ctx, int events, int flags, int vendor_id, int product_id, int dev_class, libusb_hotplug_callback_fn cb_fn, void *user_data, libusb_hotplug_callback_handle *callback_handle);
+    int (LIBUSB_CALL *hotplug_register_callback)(libusb_context *ctx, libusb_hotplug_event events, libusb_hotplug_flag flags, int vendor_id, int product_id, int dev_class, libusb_hotplug_callback_fn cb_fn, void *user_data, libusb_hotplug_callback_handle *callback_handle);
     void (LIBUSB_CALL *hotplug_deregister_callback)(libusb_context *ctx, libusb_hotplug_callback_handle callback_handle);
     const char * (LIBUSB_CALL *error_name)(int errcode);
 /* *INDENT-ON* */ // clang-format on
