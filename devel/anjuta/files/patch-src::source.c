--- src/source.c.orig	Thu Apr  8 00:15:35 2004
+++ src/source.c	Tue Apr 13 13:26:20 2004
@@ -335,7 +335,7 @@
 	{
 		fprintf (fp,
 			 "dnl Set PACKAGE DIRs in config.h.\n"
-			 "packagepixmapsdir=share/pixmaps/${PACKAGE}\n"
+			 "packagepixmapsdir=share/gnome/pixmaps/${PACKAGE}\n"
 			 "packagehelpdir=share/gnome/help/${PACKAGE}\n"
 			 "packagemenudir=share/gnome/apps\n");
 	}
