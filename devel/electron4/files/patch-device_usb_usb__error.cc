--- device/usb/usb_error.cc.orig	2019-03-15 06:25:44 UTC
+++ device/usb/usb_error.cc
@@ -9,7 +9,7 @@
 namespace device {
 
 std::string ConvertPlatformUsbErrorToString(int errcode) {
-  return libusb_strerror(static_cast<libusb_error>(errcode));
+  return "";
 }
 
 }  // namespace device
