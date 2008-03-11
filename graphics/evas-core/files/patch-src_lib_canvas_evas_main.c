--- src/lib/canvas/evas_main.c.orig	2007-10-08 23:06:27.000000000 +0400
+++ src/lib/canvas/evas_main.c	2008-02-23 18:03:58.000000000 +0300
@@ -702,58 +702,23 @@
 {
    Evas_List *methods = NULL;
 
-   /* FIXME: get from modules - this is currently coded-in */
-#ifdef BUILD_ENGINE_SOFTWARE_DDRAW
    methods = evas_list_append(methods, strdup("software_ddraw"));
-#endif
-#ifdef BUILD_ENGINE_SOFTWARE_16_DDRAW
    methods = evas_list_append(methods, strdup("software_16_ddraw"));
-#endif
-#ifdef BUILD_ENGINE_DIRECT3D
    methods = evas_list_append(methods, strdup("direct3d"));
-#endif
-#ifdef BUILD_ENGINE_SOFTWARE_X11
    methods = evas_list_append(methods, strdup("software_x11"));
-#endif
-#ifdef BUILD_ENGINE_XRENDER_X11
    methods = evas_list_append(methods, strdup("xrender_x11"));
-#endif
-#ifdef BUILD_ENGINE_SOFTWARE_XCB
    methods = evas_list_append(methods, strdup("software_xcb"));
-#endif
-#ifdef BUILD_ENGINE_XRENDER_XCB
    methods = evas_list_append(methods, strdup("xrender_xcb"));
-#endif
-#ifdef BUILD_ENGINE_SOFTWARE_16_X11
    methods = evas_list_append(methods, strdup("software_16_x11"));
-#endif
-#ifdef BUILD_ENGINE_GL_X11
    methods = evas_list_append(methods, strdup("gl_x11"));
-#endif
-#ifdef BUILD_ENGINE_GL_GLEW
    methods = evas_list_append(methods, strdup("gl_glew"));
-#endif
-#ifdef BUILD_ENGINE_CAIRO_X11
    methods = evas_list_append(methods, strdup("cairo_x11"));
-#endif
-#ifdef BUILD_ENGINE_DIRECTFB
    methods = evas_list_append(methods, strdup("directfb"));
-#endif
-#ifdef BUILD_ENGINE_FB
    methods = evas_list_append(methods, strdup("fb"));
-#endif
-#ifdef BUILD_ENGINE_BUFFER
    methods = evas_list_append(methods, strdup("buffer"));
-#endif
-#ifdef BUILD_ENGINE_SOFTWARE_WIN32_GDI
    methods = evas_list_append(methods, strdup("software_win32_gdi"));
-#endif
-#ifdef BUILD_ENGINE_SOFTWARE_QTOPIA
    methods = evas_list_append(methods, strdup("software_qtopia"));
-#endif
-#ifdef BUILD_ENGINE_SDL
    methods = evas_list_append(methods, strdup("software_sdl"));
-#endif
 
    return methods;
 }
