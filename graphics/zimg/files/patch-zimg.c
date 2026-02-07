--- zimg.c.orig	Sat Aug 27 21:46:20 2005
+++ zimg.c	Sat Aug 27 23:04:13 2005
@@ -2147,6 +2147,8 @@
 
 		for (current = z.label; current; current = current->next) {
 
+		    int width, height;
+
 		    int x = current->x;
 		    int y = current->y;
 
@@ -2160,8 +2162,8 @@
 			continue;
 		    }
 
-		    int width = brect[2] - brect[6];
-		    int height = brect[3] - brect[7];
+		    width = brect[2] - brect[6];
+		    height = brect[3] - brect[7];
 
 		    /* if label.x or label.y are positive, do NOT make any
 		     * check, if the text will be entirely on the image */
