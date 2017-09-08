--- adb/client/usb_libusb.cpp.orig	2017-06-20 10:50:27 UTC
+++ adb/client/usb_libusb.cpp
@@ -152,7 +156,14 @@ struct usb_handle : public ::usb_handle {
 static auto& usb_handles = *new std::unordered_map<std::string, std::unique_ptr<usb_handle>>();
 static auto& usb_handles_mutex = *new std::mutex();
 
+#if defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
 static libusb_hotplug_callback_handle hotplug_handle;
+#else
+static std::thread* device_poll_thread = nullptr;
+static bool terminate_device_poll_thread = false;
+static auto& device_poll_mutex = *new std::mutex();
+static auto& device_poll_cv = *new std::condition_variable();
+#endif
 
 static std::string get_device_address(libusb_device* device) {
     return StringPrintf("usb:%d:%d", libusb_get_bus_number(device),
@@ -380,6 +391,7 @@ static void process_device(libusb_device* device) {
     LOG(INFO) << "registered new usb device '" << device_serial << "'";
 }
 
+#if defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
 static std::atomic<int> connecting_devices(0);
 
 static void device_connected(libusb_device* device) {
@@ -449,7 +461,31 @@ static int hotplug_callback(libusb_context*, libusb_de
     hotplug_queue.Push({event, device});
     return 0;
 }
+#else
+static void poll_for_devices() {
+    libusb_device** list;
+    adb_thread_setname("device poll");
+    while (true) {
+        const ssize_t device_count = libusb_get_device_list(nullptr, &list);
 
+        LOG(VERBOSE) << "found " << device_count << " attached devices";
+
+        for (ssize_t i = 0; i < device_count; ++i) {
+            process_device(list[i]);
+        }
+
+        libusb_free_device_list(list, 1);
+
+        adb_notify_device_scan_complete();
+
+        std::unique_lock<std::mutex> lock(device_poll_mutex);
+        if (device_poll_cv.wait_for(lock, 500ms, []() { return terminate_device_poll_thread; })) {
+            return;
+        }
+    }
+}
+#endif
+
 void usb_init() {
     LOG(DEBUG) << "initializing libusb...";
     int rc = libusb_init(nullptr);
@@ -457,6 +493,7 @@ void usb_init() {
         LOG(FATAL) << "failed to initialize libusb: " << libusb_error_name(rc);
     }
 
+#if defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
     // Register the hotplug callback.
     rc = libusb_hotplug_register_callback(
         nullptr, static_cast<libusb_hotplug_event>(LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED |
@@ -467,6 +504,7 @@ void usb_init() {
     if (rc != LIBUSB_SUCCESS) {
         LOG(FATAL) << "failed to register libusb hotplug callback";
     }
+#endif
 
     // Spawn a thread for libusb_handle_events.
     std::thread([]() {
@@ -475,10 +513,28 @@ void usb_init() {
             libusb_handle_events(nullptr);
         }
     }).detach();
+
+#if !defined(LIBUSB_API_VERSION) || LIBUSB_API_VERSION < 0x01000102
+    std::unique_lock<std::mutex> lock(device_poll_mutex);
+    device_poll_thread = new std::thread(poll_for_devices);
+#endif
 }
 
 void usb_cleanup() {
+#if defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
     libusb_hotplug_deregister_callback(nullptr, hotplug_handle);
+#else
+    {
+        std::unique_lock<std::mutex> lock(device_poll_mutex);
+        terminate_device_poll_thread = true;
+
+        if (!device_poll_thread) {
+            return;
+        }
+    }
+    device_poll_cv.notify_all();
+    device_poll_thread->join();
+#endif
 }
 
 // Dispatch a libusb transfer, unlock |device_lock|, and then wait for the result.
