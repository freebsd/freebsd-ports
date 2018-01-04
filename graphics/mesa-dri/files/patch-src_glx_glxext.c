# work-around for https://bugs.freedesktop.org/show_bug.cgi?id=100627
#
--- src/glx/glxext.c.orig	2017-12-21 17:31:21 UTC
+++ src/glx/glxext.c
@@ -920,7 +920,11 @@ __glXInitialize(Display * dpy)
 #if defined(GLX_USE_DRM)
    if (glx_direct && glx_accel) {
 #if defined(HAVE_DRI3)
+#if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__)) && !defined(__DRM_NEXT__)
+      if (env_var_as_boolean("LIBGL_DRI3_ENABLE", false) && !env_var_as_boolean("LIBGL_DRI3_DISABLE", false))
+#else
       if (!env_var_as_boolean("LIBGL_DRI3_DISABLE", false))
+#endif
          dpyPriv->dri3Display = dri3_create_display(dpy);
 #endif /* HAVE_DRI3 */
       dpyPriv->dri2Display = dri2CreateDisplay(dpy);
