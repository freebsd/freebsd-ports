--- src/input/fontio/agl_ttfio.c.orig	2007-12-12 23:42:15.000000000 +0100
+++ src/input/fontio/agl_ttfio.c	2007-12-12 23:43:00.000000000 +0100
@@ -481,7 +481,7 @@
 	return 1;
 }
 
-static agl_fontio agl_ttf_fontio = {
+agl_fontio agl_ttf_fontio = {
 	agl_ttfis,
 	agl_ttfopen,
 	agl_ttfloadglyph,
