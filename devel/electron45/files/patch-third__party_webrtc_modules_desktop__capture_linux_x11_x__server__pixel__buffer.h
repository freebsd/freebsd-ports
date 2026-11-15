--- third_party/webrtc/modules/desktop_capture/linux/x11/x_server_pixel_buffer.h.orig	2026-06-23 23:37:18 UTC
+++ third_party/webrtc/modules/desktop_capture/linux/x11/x_server_pixel_buffer.h
@@ -17,6 +17,10 @@
 #include <X11/Xlib.h>
 #include <X11/extensions/XShm.h>
 
+#if defined(__OpenBSD__)
+#include <xcb/xcb.h>
+#endif
+
 #include <cstdint>
 #include <vector>
 
@@ -84,6 +88,11 @@ class XServerPixelBuffer {
   bool xshm_attached_ = false;
   bool xshm_get_image_succeeded_ = false;
   std::vector<uint8_t> icc_profile_;
+
+#if defined(__OpenBSD__)
+  size_t shm_size_ = 0;
+  xcb_connection_t* xcb_connection_ = nullptr;
+#endif
 };
 
 }  // namespace webrtc
