--- arccvt.c.orig	2013-06-27 02:00:19 UTC
+++ arccvt.c
@@ -118,7 +118,7 @@ cvtfile(hdr)			/* convert a file */
 	writehdr(hdr, new);	/* write out real header */
 	fseek(new, hdr->size, 1);	/* skip over data to next header */
 	fclose(tmp);		/* all done with the file */
-	if (unlink(tempname) && warn) {
+	if (unlink(tempname) && arcwarn) {
 		printf("Cannot unsave %s\n", tempname);
 		nerrs++;
 	}
