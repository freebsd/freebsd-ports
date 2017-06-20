--- adb/client/usb_libusb.cpp.orig	2017-06-20 10:50:27 UTC
+++ adb/client/usb_libusb.cpp
@@ -28,7 +28,7 @@
 #include <thread>
 #include <unordered_map>
 
-#include <libusb/libusb.h>
+#include <libusb.h>
 
 #include <android-base/file.h>
 #include <android-base/logging.h>
@@ -89,7 +89,11 @@ struct transfer_info {
 };
 
 namespace libusb {
+#if defined(__linux__) || defined(__APPLE__)
 struct usb_handle : public ::usb_handle {
+#else
+struct usb_handle {
+#endif
     usb_handle(const std::string& device_address, const std::string& serial,
                unique_device_handle&& device_handle, uint8_t interface, uint8_t bulk_in,
                uint8_t bulk_out, size_t zero_mask, size_t max_packet_size)
@@ -152,7 +156,9 @@ struct usb_handle : public ::usb_handle {
 static auto& usb_handles = *new std::unordered_map<std::string, std::unique_ptr<usb_handle>>();
 static auto& usb_handles_mutex = *new std::mutex();
 
+#if defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
 static libusb_hotplug_callback_handle hotplug_handle;
+#endif
 
 static std::string get_device_address(libusb_device* device) {
     return StringPrintf("usb:%d:%d", libusb_get_bus_number(device),
@@ -420,6 +426,7 @@ static void device_disconnected(libusb_device* device)
     }
 }
 
+#if defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
 static auto& hotplug_queue = *new BlockingQueue<std::pair<libusb_hotplug_event, libusb_device*>>();
 static void hotplug_thread() {
     adb_thread_setname("libusb hotplug");
@@ -449,6 +456,7 @@ static int hotplug_callback(libusb_context*, libusb_de
     hotplug_queue.Push({event, device});
     return 0;
 }
+#endif
 
 void usb_init() {
     LOG(DEBUG) << "initializing libusb...";
@@ -457,6 +465,7 @@ void usb_init() {
         LOG(FATAL) << "failed to initialize libusb: " << libusb_error_name(rc);
     }
 
+#if defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
     // Register the hotplug callback.
     rc = libusb_hotplug_register_callback(
         nullptr, static_cast<libusb_hotplug_event>(LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED |
@@ -467,6 +476,9 @@ void usb_init() {
     if (rc != LIBUSB_SUCCESS) {
         LOG(FATAL) << "failed to register libusb hotplug callback";
     }
+#else
+    LOG(FATAL) << "libusb doesn't support hotplug but scanning isn't implemented";
+#endif
 
     // Spawn a thread for libusb_handle_events.
     std::thread([]() {
@@ -478,7 +490,9 @@ void usb_init() {
 }
 
 void usb_cleanup() {
+#if defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
     libusb_hotplug_deregister_callback(nullptr, hotplug_handle);
+#endif
 }
 
 // Dispatch a libusb transfer, unlock |device_lock|, and then wait for the result.
