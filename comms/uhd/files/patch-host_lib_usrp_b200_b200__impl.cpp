--- host/lib/usrp/b200/b200_impl.cpp.orig	2026-10-16 14:05:41 UTC
+++ host/lib/usrp/b200/b200_impl.cpp
@@ -470,6 +470,15 @@ b200_impl::b200_impl(
 
     _iface->reset_gpif();
 
+    {
+        libusb::device_handle::sptr dev_handle(libusb::device_handle::get_cached_handle(
+            std::static_pointer_cast<libusb::special_handle>(handle)->get_device()));
+        dev_handle->clear_endpoints(
+            B200_USB_CTRL_RECV_ENDPOINT, B200_USB_CTRL_SEND_ENDPOINT);
+        dev_handle->clear_endpoints(
+            B200_USB_DATA_RECV_ENDPOINT, B200_USB_DATA_SEND_ENDPOINT);
+    }
+
     ////////////////////////////////////////////////////////////////////
     // Create control transport
     ////////////////////////////////////////////////////////////////////
