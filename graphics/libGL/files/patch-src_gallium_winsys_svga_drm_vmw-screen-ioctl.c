diff --git a/src/gallium/winsys/svga/drm/vmw_screen_ioctl.c b/src/gallium/winsys/svga/drm/vmw_screen_ioctl.c
index 36888dc..62a6e6a 100644
--- src/gallium/winsys/svga/drm/vmw_screen_ioctl.c
+++ src/gallium/winsys/svga/drm/vmw_screen_ioctl.c
@@ -66,6 +66,13 @@ struct vmw_region
  */
 #define SVGA3D_SURFACE_HINT_SCANOUT (1 << 9)
 
+#if defined(__DragonFly__) || \
+    defined(__FreeBSD__) ||   \
+    defined(__NetBSD__) ||    \
+    defined(__OpenBSD__)
+#define	ERESTART EINTR
+#endif
+
 uint32
 vmw_ioctl_context_create(struct vmw_winsys_screen *vws)
 {
