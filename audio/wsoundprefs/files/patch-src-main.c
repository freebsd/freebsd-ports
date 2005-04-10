--- src/main.c.orig	Mon Jun 14 17:28:23 1999
+++ src/main.c	Sun Apr 10 20:51:47 2005
@@ -109,9 +109,9 @@
 			wwarning(_("could not load image file %s:%s"), path, RMessageForError(RErrorCode));
 		else {
 			icon = WMCreatePixmapFromRImage(scr, tmp, 0);
-			RDestroyImage(tmp);
+			RReleaseImage(tmp);
 			if (icon) {
-				WMSetApplicationIconImage(scr, icon);
+				WMSetApplicationIconPixmap(scr, icon);
 				WMReleasePixmap(icon);
 			}
 		}
