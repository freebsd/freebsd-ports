--- src/cairo-gl.h.orig	2015-03-10 22:21:07 UTC
+++ src/cairo-gl.h
@@ -92,7 +92,7 @@ cairo_public void
 cairo_gl_device_set_thread_aware (cairo_device_t	*device,
 				  cairo_bool_t		 thread_aware);
 
-#if CAIRO_HAS_GLX_FUNCTIONS
+#if defined(CAIRO_HAS_GLX_FUNCTIONS)
 #include <GL/glx.h>
 
 cairo_public cairo_device_t *
@@ -110,7 +110,7 @@ cairo_gl_surface_create_for_window (cair
 				    int width, int height);
 #endif
 
-#if CAIRO_HAS_WGL_FUNCTIONS
+#if defined(CAIRO_HAS_WGL_FUNCTIONS)
 #include <windows.h>
 
 cairo_public cairo_device_t *
@@ -126,7 +126,7 @@ cairo_gl_surface_create_for_dc (cairo_de
 				int			 height);
 #endif
 
-#if CAIRO_HAS_EGL_FUNCTIONS
+#if defined(CAIRO_HAS_EGL_FUNCTIONS)
 #include <EGL/egl.h>
 
 cairo_public cairo_device_t *
