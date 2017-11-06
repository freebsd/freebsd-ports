# work-around for https://bugs.freedesktop.org/show_bug.cgi?id=100627
#
--- src/glx/glxext.c.orig	2017-04-01 15:33:37 UTC
+++ src/glx/glxext.c
@@ -906,7 +906,11 @@ __glXInitialize(Display * dpy)
 #if defined(GLX_USE_DRM)
    if (glx_direct && glx_accel) {
 #if defined(HAVE_DRI3)
+#if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__)) && !defined (__DRM_NEXT__)
+      if (getenv("LIBGL_DRI3_ENABLE") && !getenv("LIBGL_DRI3_DISABLE"))
+#else
       if (!getenv("LIBGL_DRI3_DISABLE"))
+#endif
          dpyPriv->dri3Display = dri3_create_display(dpy);
 #endif /* HAVE_DRI3 */
       dpyPriv->dri2Display = dri2CreateDisplay(dpy);
