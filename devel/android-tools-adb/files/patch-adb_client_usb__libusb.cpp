--- adb/client/usb_libusb.cpp.orig	2017-06-20 10:50:27 UTC
+++ adb/client/usb_libusb.cpp
@@ -22,13 +22,14 @@
 
 #include <atomic>
 #include <chrono>
+#include <condition_variable>
 #include <memory>
 #include <mutex>
 #include <string>
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
