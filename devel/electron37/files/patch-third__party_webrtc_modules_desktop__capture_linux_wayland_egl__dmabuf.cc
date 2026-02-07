--- third_party/webrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc.orig	2025-04-22 20:15:27 UTC
+++ third_party/webrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc
@@ -11,7 +11,9 @@
 #include "modules/desktop_capture/linux/wayland/egl_dmabuf.h"
 
 #include <EGL/eglext.h>
+#if !defined(WEBRTC_BSD)
 #include <asm/ioctl.h>
+#endif
 #include <dlfcn.h>
 #include <fcntl.h>
 #include <libdrm/drm_fourcc.h>
