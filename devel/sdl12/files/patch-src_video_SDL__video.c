
$FreeBSD$

--- src/video/SDL_video.c	2001/01/21 20:11:02	1.1
+++ src/video/SDL_video.c	2001/01/21 20:11:59
@@ -60,6 +60,9 @@
 #ifdef ENABLE_SVGALIB
 	&SVGALIB_bootstrap,
 #endif
+#ifdef ENABLE_VGL
+	&VGL_bootstrap,
+#endif
 #ifdef ENABLE_AALIB
     &AALIB_bootstrap,
 #endif
