--- arcext.c.orig	2013-06-27 02:00:19 UTC
+++ arcext.c
@@ -141,7 +141,7 @@ extfile(hdr, path, prt)		/* extract a file */
 	if (note)
 		printf("Extracting file: %s\n", fix);
 
-	if (warn && !overlay) {
+	if (arcwarn && !overlay) {
 		if ((f = fopen(fix, "r"))) {	/* see if it exists */
 				fclose(f);
 				printf("WARNING: File %s already exists!", fix);
@@ -189,7 +189,7 @@ extfile(hdr, path, prt)		/* extract a file */
 	if (!f)
 #endif
 	{
-		if (warn) {
+		if (arcwarn) {
 			printf("Cannot create %s\n", fix);
 			nerrs++;
 		}
