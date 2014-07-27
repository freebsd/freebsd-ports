--- ./arclzw.c.orig	Tue Aug 10 23:03:25 1999
+++ ./arclzw.c	Tue Aug 10 23:01:57 1999
@@ -546,7 +546,7 @@
 		 */
 		if (code >= free_ent) {
 			if (code > free_ent) {
-				if (warn) {
+				if (arcwarn) {
 					printf("Corrupted compressed file.\n");
 					printf("Invalid code %d when max is %d.\n",
 					       code, free_ent);
