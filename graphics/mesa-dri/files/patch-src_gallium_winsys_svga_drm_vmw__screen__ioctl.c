--- src/gallium/winsys/svga/drm/vmw_screen_ioctl.c.orig	2016-11-10 22:05:17 UTC
+++ src/gallium/winsys/svga/drm/vmw_screen_ioctl.c
@@ -70,6 +70,11 @@ vmw_region_size(struct vmw_region *regio
    return region->size;
 }
 
+#if defined(__DragonFly__) || defined(__FreeBSD__) || \
+    defined(__NetBSD__) || defined(__OpenBSD__)
+#define ERESTART EINTR
+#endif
+
 uint32
 vmw_ioctl_context_create(struct vmw_winsys_screen *vws)
 {
