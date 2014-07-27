--- ./arccvt.c.orig	Tue Aug 10 23:03:24 1999
+++ ./arccvt.c	Tue Aug 10 23:01:55 1999
@@ -120,7 +120,7 @@
 	writehdr(hdr, new);	/* write out real header */
 	fseek(new, hdr->size, 1);	/* skip over data to next header */
 	fclose(tmp);		/* all done with the file */
-	if (unlink(tempname) && warn) {
+	if (unlink(tempname) && arcwarn) {
 		printf("Cannot unsave %s\n", tempname);
 		nerrs++;
 	}
