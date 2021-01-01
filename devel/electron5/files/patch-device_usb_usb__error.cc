--- device/usb/usb_error.cc.orig	2019-04-08 08:18:20 UTC
+++ device/usb/usb_error.cc
@@ -9,7 +9,7 @@
 namespace device {
 
 std::string ConvertPlatformUsbErrorToString(int errcode) {
-  return libusb_strerror(static_cast<libusb_error>(errcode));
+  return "";
 }
 
 }  // namespace device
