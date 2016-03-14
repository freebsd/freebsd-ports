--- util.c.orig	1998-10-25 19:55:11 UTC
+++ util.c
@@ -537,7 +537,7 @@ msgcpy(char *dst, char *src, int n)
 	** Now make sure we didn't chop a word in the middle.
 	*/
 	if (*src && end) {
-		*end++ = '\0';
+		*++end = '\0';
 		src = start;
 	}
 
