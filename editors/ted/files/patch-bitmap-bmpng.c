--- bitmap/bmpng.c.orig	2009-10-16 17:20:57.000000000 +0200
+++ bitmap/bmpng.c	2010-03-29 21:20:37.000000000 +0200
@@ -284,7 +284,6 @@
 				png_info *			pngi,
 				const BitmapDescription *       bd )
     {
-    png_info_init( pngi );
     pngi->width= bd->bdPixelsWide;
     pngi->height= bd->bdPixelsHigh;
 
