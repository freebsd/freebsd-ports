
$FreeBSD$

--- src/video/SDL_sysvideo.h	2001/01/21 20:12:21	1.1
+++ src/video/SDL_sysvideo.h	2001/01/21 20:12:51
@@ -331,6 +331,9 @@
 #ifdef ENABLE_SVGALIB
 extern VideoBootStrap SVGALIB_bootstrap;
 #endif
+#ifdef ENABLE_VGL
+extern VideoBootStrap VGL_bootstrap;
+#endif
 #ifdef ENABLE_AALIB
 extern VideoBootStrap AALIB_bootstrap;
 #endif
