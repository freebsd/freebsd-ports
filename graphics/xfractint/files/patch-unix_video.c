--- unix/video.c.orig	2014-05-03 13:12:33 UTC
+++ unix/video.c
@@ -11,7 +11,7 @@
  * Copyright 1992 Ken Shirriff
  */
 
-WINDOW *curwin;
+extern WINDOW *curwin;
 
 extern unsigned char *xgetfont (void);
 extern int startdisk (void);
@@ -44,7 +44,7 @@ int color_dark = 0;		/* darkest color in palette */
 int color_bright = 0;		/* brightest color in palette */
 int color_medium = 0;		/* nearest to medbright grey in palette
 				   Zoom-Box values (2K x 2K screens max) */
-int boxcolor = 0;		/* Zoom-Box color */
+extern int boxcolor;		/* Zoom-Box color */
 int reallyega = 0;		/* 1 if its an EGA posing as a VGA */
 int gotrealdac = 0;		/* 1 if loaddac has a dacbox */
 int rowcount = 0;		/* row-counter for decoder and out_line */
