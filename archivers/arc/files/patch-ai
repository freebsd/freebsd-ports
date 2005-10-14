--- arcext.c.orig	Sat Oct  8 22:24:37 2005
+++ arcext.c	Fri Oct 14 00:52:14 2005
@@ -143,7 +143,7 @@
 	if (note)
 		printf("Extracting file: %s\n", fix);
 
-	if (warn && !overlay) {
+	if (arcwarn && !overlay) {
 		if ((f = fopen(fix, "r"))) {	/* see if it exists */
 				fclose(f);
 				printf("WARNING: File %s already exists!", fix);
@@ -190,7 +190,7 @@
 	if (!f)
 #endif
 	{
-		if (warn) {
+		if (arcwarn) {
 			printf("Cannot create %s\n", fix);
 			nerrs++;
 		}
