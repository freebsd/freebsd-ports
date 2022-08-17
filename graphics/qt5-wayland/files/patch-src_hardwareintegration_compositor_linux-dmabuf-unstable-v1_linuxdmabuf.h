--- src/hardwareintegration/compositor/linux-dmabuf-unstable-v1/linuxdmabuf.h.orig	2022-06-20 20:17:21 UTC
+++ src/hardwareintegration/compositor/linux-dmabuf-unstable-v1/linuxdmabuf.h
@@ -46,6 +46,8 @@
 #include <EGL/egl.h>
 #include <EGL/eglext.h>
 
+#include <array>
+
 // compatibility with libdrm <= 2.4.74
 #ifndef DRM_FORMAT_RESERVED
 #define DRM_FORMAT_RESERVED           ((1ULL << 56) - 1)
