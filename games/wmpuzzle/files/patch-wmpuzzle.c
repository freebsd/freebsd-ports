--- wmpuzzle.c.orig	Mon Oct 21 22:26:35 2002
+++ wmpuzzle.c	Sun Oct 27 17:28:07 2002
@@ -254,8 +254,8 @@
 		}
 	}
 	if (image == NULL) {
-		image = strdup("linux");
-		*wmpuzzle = linux_xpm;
+		image = strdup("daemon");
+		*wmpuzzle = daemon_xpm;
 	}
 }
 
