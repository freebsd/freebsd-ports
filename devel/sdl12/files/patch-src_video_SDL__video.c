
$FreeBSD$

--- src/video/SDL_video.c.orig	Mon Mar 19 19:39:06 2001
+++ src/video/SDL_video.c	Sun Apr  8 01:34:24 2001
@@ -60,6 +60,9 @@
 #ifdef ENABLE_GGI
 	&GGI_bootstrap,
 #endif
+#ifdef ENABLE_VGL
+	&VGL_bootstrap,
+#endif
 #ifdef ENABLE_SVGALIB
 	&SVGALIB_bootstrap,
 #endif
