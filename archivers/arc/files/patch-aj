--- arcio.c.orig	Wed Apr 15 02:58:26 1992
+++ arcio.c	Sat Aug 11 22:10:55 2001
@@ -46,7 +46,7 @@
 		return 0;	/* then signal end of archive */
 
 	if (hdrver != ARCMARK) {	/* check archive validity */
-		if (warn) {
+		if (arcwarn) {
 			printf("An entry in %s has a bad header.\n", arcname);
 			nerrs++;
 		}
@@ -63,10 +63,10 @@
 		if (feof(f) && first)
 			arcdie("%s is not an archive", arcname);
 
-		if (changing && warn)
+		if (changing && arcwarn)
 			arcdie("%s is corrupted -- changes disallowed", arcname);
 
-		if (warn)
+		if (arcwarn)
 			printf("  %d bytes skipped.\n", try);
 
 		if (feof(f))
@@ -110,7 +110,8 @@
 	hdr->crc = (short) ((dummy[22] << 8) + dummy[21]);
 	for (i = 0, hdr->length=0; i<4; hdr->length<<=8, hdr->length += dummy[26-i], i++);
 #endif
-
+	if (hdr->size < 0)
+		arcdie("Invalid header in archive %s", arcname);
 	if (hdr->date > olddate
 	    || (hdr->date == olddate && hdr->time > oldtime)) {
 		olddate = hdr->date;
