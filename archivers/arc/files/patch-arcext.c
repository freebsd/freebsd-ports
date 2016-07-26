--- arcext.c.orig	2010-08-07 13:06:42 UTC
+++ arcext.c
@@ -143,7 +143,7 @@ extfile(hdr, path, prt)		/* extract a fi
 	if (note)
 		printf("Extracting file: %s\n", fix);
 
-	if (warn && !overlay) {
+	if (arcwarn && !overlay) {
 		if ((f = fopen(fix, "r"))) {	/* see if it exists */
 				fclose(f);
 				printf("WARNING: File %s already exists!", fix);
@@ -191,7 +191,7 @@ extfile(hdr, path, prt)		/* extract a fi
 	if (!f)
 #endif
 	{
-		if (warn) {
+		if (arcwarn) {
 			printf("Cannot create %s\n", fix);
 			nerrs++;
 		}
