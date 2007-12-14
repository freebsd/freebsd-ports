--- src/input/fontio/agl_bfontio.c	2007-12-12 23:43:53.000000000 +0100
+++ src/input/fontio/agl_bfontio.c.orig	2007-12-12 23:43:41.000000000 +0100
@@ -387,7 +387,7 @@
 	return 0;
 }
 
-static agl_fontio agl_bfnt_fontio = {
+agl_fontio agl_bfnt_fontio = {
 	agl_bfntis,
 	agl_bfntopen,
 	agl_bfntloadglyph,
