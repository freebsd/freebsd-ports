--- src/source.c.orig	Wed May 14 14:17:11 2003
+++ src/source.c	Wed May 14 14:17:23 2003
@@ -314,7 +314,7 @@
 		 "fi\n\n");
 	fprintf (fp,
 		 "dnl Set PACKAGE DATA & DOC DIR\n"
-		 "packagedatadir=share/${PACKAGE}\n"
+		 "packagedatadir=share/gnome/${PACKAGE}\n"
 		 "packagedocdir=doc/${PACKAGE}\n"
 		 "\n");
 	
@@ -332,7 +332,7 @@
 	{
 		fprintf (fp,
 			 "dnl Set PACKAGE DIRs in config.h.\n"
-			 "packagepixmapsdir=share/pixmaps/${PACKAGE}\n"
+			 "packagepixmapsdir=share/gnome/pixmaps/${PACKAGE}\n"
 			 "packagehelpdir=share/gnome/help/${PACKAGE}\n"
 			 "packagemenudir=share/gnome/apps\n");
 	}
