--- util.c.orig	Sun Oct 25 20:55:11 1998
+++ util.c	Thu Oct 28 23:58:37 2004
@@ -537,7 +537,7 @@
 	** Now make sure we didn't chop a word in the middle.
 	*/
 	if (*src && end) {
-		*end++ = '\0';
+		*++end = '\0';
 		src = start;
 	}
 
