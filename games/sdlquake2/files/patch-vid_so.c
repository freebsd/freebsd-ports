--- ./vid_so.c.orig	Thu May 19 17:56:13 2005
+++ ./vid_so.c	Sun Feb 26 11:23:56 2006
@@ -225,7 +225,7 @@
 		fn[strlen(fn) - 1] = 0;
 	*/
 
-	strcpy (fn, ".");
+	strcpy (fn, LIBDIR);
 	strcat(fn, "/");
 	strcat(fn, name);
 
