--- gtkmain.c.orig	Sun Sep  7 23:48:20 2003
+++ gtkmain.c	Sun Sep  7 23:48:30 2003
@@ -143,7 +143,7 @@
 
 #ifdef unix
 	if(getenv("TDHOME"))
-	    chdir(getenv("TDHOME"))
+	    chdir(getenv("TDHOME"));
 #endif
 	screen_width = gdk_screen_width();
 
