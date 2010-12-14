--- src/lib/canvas/evas_main.c.orig	2010-12-11 14:16:03.000000000 -0800
+++ src/lib/canvas/evas_main.c	2010-12-11 14:17:30.000000000 -0800
@@ -808,45 +808,29 @@
 #ifdef BUILD_ENGINE_SOFTWARE_16_WINCE
    methods = eina_list_append(methods, "software_16_wince");
 #endif
-#ifdef BUILD_ENGINE_SOFTWARE_X11
    methods = eina_list_append(methods, "software_x11");
-#endif
-#ifdef BUILD_ENGINE_XRENDER_X11
    methods = eina_list_append(methods, "xrender_x11");
-#endif
-#ifdef BUILD_ENGINE_XRENDER_XCB
    methods = eina_list_append(methods, "xrender_xcb");
-#endif
-#ifdef BUILD_ENGINE_SOFTWARE_16_X11
    methods = eina_list_append(methods, "software_16_x11");
-#endif
-#ifdef BUILD_ENGINE_GL_X11
    methods = eina_list_append(methods, "gl_x11");
-#endif
 #ifdef BUILD_ENGINE_GL_GLEW
    methods = eina_list_append(methods, "gl_glew");
 #endif
-#ifdef BUILD_ENGINE_CAIRO_X11
    methods = eina_list_append(methods, "cairo_x11");
-#endif
 #ifdef BUILD_ENGINE_DIRECTFB
    methods = eina_list_append(methods, "directfb");
 #endif
 #ifdef BUILD_ENGINE_FB
    methods = eina_list_append(methods, "fb");
 #endif
-#ifdef BUILD_ENGINE_BUFFER
    methods = eina_list_append(methods, "buffer");
-#endif
 #ifdef BUILD_ENGINE_SOFTWARE_WIN32_GDI
    methods = eina_list_append(methods, "software_win32_gdi");
 #endif
 #ifdef BUILD_ENGINE_SOFTWARE_QTOPIA
    methods = eina_list_append(methods, "software_qtopia");
 #endif
-#ifdef BUILD_ENGINE_SOFTWARE_SDL
    methods = eina_list_append(methods, "software_sdl");
-#endif
 
    return methods;
 }
