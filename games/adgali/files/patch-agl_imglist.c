--- tools/agl_imglist.c.orig	Fri Aug 20 22:20:31 2004
+++ tools/agl_imglist.c	Fri Aug 20 22:20:48 2004
@@ -137,6 +137,7 @@
 				x++;
 			}
 		      next:
+			break;
 		}
 	}
 	fclose(textfile);
