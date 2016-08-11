--- arclzw.c.orig	2010-08-07 13:06:42 UTC
+++ arclzw.c
@@ -560,7 +560,7 @@ decomp(squash, f, t)		/* decompress a fi
 		 */
 		if (code >= free_ent) {
 			if (code > free_ent) {
-				if (warn) {
+				if (arcwarn) {
 					printf("Corrupted compressed file.\n");
 					printf("Invalid code %d when max is %d.\n",
 					       code, free_ent);
