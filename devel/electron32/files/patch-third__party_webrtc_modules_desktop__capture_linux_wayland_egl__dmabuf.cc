--- third_party/webrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc.orig	2023-08-16 00:44:33 UTC
+++ third_party/webrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc
@@ -10,11 +10,15 @@
 
 #include "modules/desktop_capture/linux/wayland/egl_dmabuf.h"
 
+#if !defined(WEBRTC_BSD)
 #include <asm/ioctl.h>
+#endif
 #include <dlfcn.h>
 #include <fcntl.h>
 #include <libdrm/drm_fourcc.h>
+#if !defined(WEBRTC_BSD)
 #include <linux/types.h>
+#endif
 #include <spa/param/video/format-utils.h>
 #include <unistd.h>
 #include <xf86drm.h>
