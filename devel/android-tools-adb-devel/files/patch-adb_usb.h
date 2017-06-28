--- adb/usb.h.orig	2017-06-20 10:50:27 UTC
+++ adb/usb.h
@@ -43,6 +43,7 @@ namespace libusb {
     ADB_USB_INTERFACE(libusb::usb_handle*);
 }
 
+#if defined(__linux__) || defined(__APPLE__)
 namespace native {
     struct usb_handle;
     ADB_USB_INTERFACE(native::usb_handle*);
@@ -53,6 +54,9 @@ struct usb_handle {
 };
 
 ADB_USB_INTERFACE(::usb_handle*);
+#else
+using namespace libusb;
+#endif
 
 #endif // linux host || darwin
 
