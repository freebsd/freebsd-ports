--- arcio.c.orig	2010-08-07 13:06:42 UTC
+++ arcio.c
@@ -46,7 +46,7 @@ readhdr(hdr, f)			/* read a header from 
 		return 0;	/* then signal end of archive */
 
 	if (hdrver != ARCMARK) {	/* check archive validity */
-		if (warn) {
+		if (arcwarn) {
 			printf("An entry in %s has a bad header.\n", arcname);
 			nerrs++;
 		}
@@ -67,10 +67,10 @@ readhdr(hdr, f)			/* read a header from 
 		if (feof(f) && first)
 			arcdie("%s is not an archive", arcname);
 
-		if (changing && warn)
+		if (changing && arcwarn)
 			arcdie("%s is corrupted -- changes disallowed", arcname);
 
-		if (warn)
+		if (arcwarn)
 			printf("  %d bytes skipped.\n", try);
 
 		if (feof(f))
@@ -118,7 +118,8 @@ readhdr(hdr, f)			/* read a header from 
 	hdr->crc = (short) ((dummy[22] << 8) + dummy[21]);
 	for (i = 0, hdr->length=0; i<4; hdr->length<<=8, hdr->length += dummy[26-i], i++);
 #endif
-
+	if (hdr->size < 0)
+		arcdie("Invalid header in archive %s", arcname);
 	if (hdr->date > olddate
 	    || (hdr->date == olddate && hdr->time > oldtime)) {
 		olddate = hdr->date;
