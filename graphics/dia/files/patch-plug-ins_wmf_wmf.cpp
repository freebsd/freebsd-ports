https://gitlab.gnome.org/GNOME/dia/commit/5cb4adf2d2c5

--- plug-ins/wmf/wmf.cpp.orig	2014-08-24 15:46:01 UTC
+++ plug-ins/wmf/wmf.cpp
@@ -61,8 +61,10 @@ typedef W32::LOGFONTW LOGFONTW;
 #  define SAVE_EMF
 #endif
 
+#ifdef G_OS_WIN32
 /* force linking with gdi32 */
 #pragma comment( lib, "gdi32" )
+#endif
 
 
 // #define SAVE_EMF
