--- cogl/winsys/cogl-winsys-egl.c.orig	2016-08-26 16:18:16 UTC
+++ cogl/winsys/cogl-winsys-egl.c
@@ -1029,7 +1029,7 @@ _cogl_egl_create_image (CoglContext *ctx,
     egl_ctx = EGL_NO_CONTEXT;
   else
 #endif
-#if COGL_HAS_WAYLAND_EGL_SERVER_SUPPORT
+#ifdef COGL_HAS_WAYLAND_EGL_SERVER_SUPPORT
   /* The WL_bind_wayland_display spec states that EGL_NO_CONTEXT is to be used
    * in conjunction with the EGL_WAYLAND_BUFFER_WL target */
   if (target == EGL_WAYLAND_BUFFER_WL)
