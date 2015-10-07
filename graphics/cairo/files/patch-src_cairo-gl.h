--- src/cairo-gl.h.orig	2013-03-15 21:29:27.000000000 +0100
+++ src/cairo-gl.h	2015-01-05 10:30:46.611768380 +0100
@@ -92,7 +92,7 @@
 cairo_gl_device_set_thread_aware (cairo_device_t	*device,
 				  cairo_bool_t		 thread_aware);
 
-#if CAIRO_HAS_GLX_FUNCTIONS
+#if defined(CAIRO_HAS_GLX_FUNCTIONS)
 #include <GL/glx.h>
 
 cairo_public cairo_device_t *
@@ -110,7 +110,7 @@
 				    int width, int height);
 #endif
 
-#if CAIRO_HAS_WGL_FUNCTIONS
+#if defined(CAIRO_HAS_WGL_FUNCTIONS)
 #include <windows.h>
 
 cairo_public cairo_device_t *
@@ -126,7 +126,7 @@
 				int			 height);
 #endif
 
-#if CAIRO_HAS_EGL_FUNCTIONS
+#if defined(CAIRO_HAS_EGL_FUNCTIONS)
 #include <EGL/egl.h>
 
 cairo_public cairo_device_t *
