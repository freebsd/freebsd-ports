--- third_party/webrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc.orig	2025-08-26 20:49:50 UTC
+++ third_party/webrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc
@@ -15,7 +15,9 @@
 #include <EGL/eglplatform.h>
 #include <GL/gl.h>
 #include <GL/glext.h>
+#if !defined(WEBRTC_BSD)
 #include <asm/ioctl.h>
+#endif
 #include <dlfcn.h>
 #include <fcntl.h>
 #include <gbm.h>
