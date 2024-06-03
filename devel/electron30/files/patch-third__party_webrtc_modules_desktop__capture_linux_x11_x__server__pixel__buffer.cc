--- third_party/webrtc/modules/desktop_capture/linux/x11/x_server_pixel_buffer.cc.orig	2024-04-15 20:35:19 UTC
+++ third_party/webrtc/modules/desktop_capture/linux/x11/x_server_pixel_buffer.cc
@@ -201,6 +201,12 @@ void XServerPixelBuffer::InitShm(const XWindowAttribut
 }
 
 void XServerPixelBuffer::InitShm(const XWindowAttributes& attributes) {
+#if defined(__OpenBSD__)
+// pledge(2)
+  RTC_LOG(LS_WARNING) << "Unable to use shmget(2) while using pledge(2). "
+                         "Performance may be degraded.";
+  return;
+#else
   Visual* default_visual = attributes.visual;
   int default_depth = attributes.depth;
 
@@ -261,6 +267,7 @@ void XServerPixelBuffer::InitShm(const XWindowAttribut
   RTC_LOG(LS_VERBOSE) << "Using X shared memory extension v" << major << "."
                       << minor << " with" << (have_pixmaps ? "" : "out")
                       << " pixmaps.";
+#endif
 }
 
 bool XServerPixelBuffer::InitPixmaps(int depth) {
