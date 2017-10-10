# work-around for https://bugs.freedesktop.org/show_bug.cgi?id=100627
#
--- src/egl/drivers/dri2/platform_x11.c.orig	2017-10-02 15:49:02 UTC
+++ src/egl/drivers/dri2/platform_x11.c
@@ -1490,7 +1490,11 @@ dri2_initialize_x11(_EGLDriver *drv, _EG
 
    if (!getenv("LIBGL_ALWAYS_SOFTWARE")) {
 #ifdef HAVE_DRI3
+#if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__)) && !defined (__DRM_NEXT__)
+      if (getenv("LIBGL_DRI3_ENABLE") && !getenv("LIBGL_DRI3_DISABLE"))
+#else
       if (!getenv("LIBGL_DRI3_DISABLE"))
+#endif
          initialized = dri2_initialize_x11_dri3(drv, disp);
 #endif
 
