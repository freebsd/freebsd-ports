--- gst-libs/gst/gl/gstglfuncs.h.orig	2018-03-23 20:44:42 UTC
+++ gst-libs/gst/gl/gstglfuncs.h
@@ -23,13 +23,6 @@
 
 #include <gst/gl/gstglconfig.h>
 
-/* This mimic GCC behaviour with system headers files even if GL headers may
- * not be in the system header path. */
-#ifdef __GNUC__
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wredundant-decls"
-#endif
-
 /* OpenGL 2.0 for Embedded Systems */
 #if GST_GL_HAVE_GLES2
 # if GST_GL_HAVE_PLATFORM_EAGL
@@ -72,10 +65,6 @@
 # endif
 #endif
 
-#ifdef __GNUC__
-#pragma GCC diagnostic pop
-#endif
-
 #if defined(WINAPI)
 #define GSTGLAPI WINAPI
 #else
