--- ./linux/vid_so.c.orig	Mon Oct 30 15:26:12 2006
+++ ./linux/vid_so.c	Sat Dec 16 17:28:37 2006
@@ -222,7 +222,7 @@
 		fn[strlen(fn) - 1] = 0;
 	*/
 
-	strcpy (fn, ".");
+	strcpy (fn, LIBDIR);
 	strcat(fn, "/");
 	strcat(fn, name);
 
