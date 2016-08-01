--- cv.c.orig	1997-06-03 18:43:52 UTC
+++ cv.c
@@ -151,7 +151,7 @@ cv_read_table (void *cv, char *fname)
 	MCHK (c);
 	if ((! c) || (! (fp = fopen (fname, "r"))))
 		return -1;
-	while (line = getline (fp, True)) {
+	while (line = get_line (fp, True)) {
 		for (sp = line; isspace (*sp); ++sp)
 			;
 		if (*sp && (*sp != '#')) {
