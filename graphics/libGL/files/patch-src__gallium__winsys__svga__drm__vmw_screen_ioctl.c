--- ./src/gallium/winsys/svga/drm/vmw_screen_ioctl.c.orig	2014-01-06 22:15:40.000000000 +0100
+++ ./src/gallium/winsys/svga/drm/vmw_screen_ioctl.c	2014-02-23 22:01:50.000000000 +0100
@@ -66,6 +66,11 @@
  */
 #define SVGA3D_SURFACE_HINT_SCANOUT (1 << 9)
 
+#if defined(__DragonFly__) || defined(__FreeBSD__) || \
+    defined(__NetBSD__) || defined(__OpenBSD__)
+#define ERESTART EINTR
+#endif
+
 uint32
 vmw_ioctl_context_create(struct vmw_winsys_screen *vws)
 {
