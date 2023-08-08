--- arcio.c.orig	2013-06-27 02:00:19 UTC
+++ arcio.c
@@ -35,6 +35,7 @@ readhdr(hdr, f)			/* read a header from an archive */
 #endif
 	char            name[FNLEN];	/* filename buffer */
 	int             try = 0;/* retry counter */
+	int             hdrlen;
 	static int      first = 1;	/* true only on first read */
 
 	if (!f)			/* if archive didn't open */
@@ -44,7 +45,7 @@ readhdr(hdr, f)			/* read a header from an archive */
 		return 0;	/* then signal end of archive */
 
 	if (hdrver != ARCMARK) {	/* check archive validity */
-		if (warn) {
+		if (arcwarn) {
 			printf("An entry in %s has a bad header.\n", arcname);
 			nerrs++;
 		}
@@ -65,10 +66,10 @@ readhdr(hdr, f)			/* read a header from an archive */
 		if (feof(f) && first)
 			arcdie("%s is not an archive", arcname);
 
-		if (changing && warn)
+		if (changing && arcwarn)
 			arcdie("%s is corrupted -- changes disallowed", arcname);
 
-		if (warn)
+		if (arcwarn)
 			printf("  %d bytes skipped.\n", try);
 
 		if (feof(f))
@@ -90,33 +91,40 @@ readhdr(hdr, f)			/* read a header from an archive */
 		printf("I think you need a newer version of ARC.\n");
 		exit(1);
 	}
+
 	/* amount to read depends on header type */
+	if (hdrver == 1) {
+		hdrlen = 23; /* old style is shorter */
+	} else {
+		hdrlen = 27;
+	}
 
-	if (hdrver == 1) {	/* old style is shorter */
-		if (fread(hdr, sizeof(struct heads) - sizeof(long int), 1, f) != 1)
-			arcdie("%s was truncated", arcname);
-		hdrver = 2;	/* convert header to new format */
-		hdr->length = hdr->size;	/* size is same when not
-						 * packed */
-	} else
-#if	MSDOS
-		if (fread(hdr, sizeof(struct heads), 1, f) != 1)
-			arcdie("%s was truncated", arcname);
-#else
-		if (fread(dummy, 27, 1, f) != 1)
-			arcdie("%s was truncated", arcname);
+	if (fread(dummy, hdrlen, 1, f) != 1)
+		arcdie("%s was truncated", arcname);
 
 	for (i = 0; i < FNLEN; hdr->name[i] = dummy[i], i++);
+	hdr->name[FNLEN - 1] = 0; /* ensure 0 termination */
 #if	_MTS
 	(void) atoe(hdr->name, strlen(hdr->name));
 #endif
+	if (strchr(hdr->name, CUTOFF) != NULL)
+		arcdie("%s contains illegal filename %s", arcname, hdr->name);
+
 	for (i = 0, hdr->size=0; i<4; hdr->size<<=8, hdr->size += dummy[16-i], i++);
 	hdr->date = (short) ((dummy[18] << 8) + dummy[17]);
 	hdr->time = (short) ((dummy[20] << 8) + dummy[19]);
 	hdr->crc = (short) ((dummy[22] << 8) + dummy[21]);
-	for (i = 0, hdr->length=0; i<4; hdr->length<<=8, hdr->length += dummy[26-i], i++);
-#endif
 
+	if (hdrver == 1) {
+		hdrver = 2;	/* convert header to new format */
+		hdr->length = hdr->size;	/* size is same when not
+						 * packed */
+	} else {
+		for (i = 0, hdr->length=0; i<4; hdr->length<<=8, hdr->length += dummy[26-i], i++);
+	}
+
+	if (hdr->size < 0)
+		arcdie("Invalid header in archive %s", arcname);
 	if (hdr->date > olddate
 	    || (hdr->date == olddate && hdr->time > oldtime)) {
 		olddate = hdr->date;
