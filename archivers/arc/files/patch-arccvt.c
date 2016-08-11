--- arccvt.c.orig	2010-08-07 13:06:42 UTC
+++ arccvt.c
@@ -120,7 +120,7 @@ cvtfile(hdr)			/* convert a file */
 	writehdr(hdr, new);	/* write out real header */
 	fseek(new, hdr->size, 1);	/* skip over data to next header */
 	fclose(tmp);		/* all done with the file */
-	if (unlink(tempname) && warn) {
+	if (unlink(tempname) && arcwarn) {
 		printf("Cannot unsave %s\n", tempname);
 		nerrs++;
 	}
