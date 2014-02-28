--- src/ps2raster.c.orig
+++ src/ps2raster.c
@@ -505,7 +505,7 @@
 	for (k = 0; k < n_files; k++) {
 		excessK = FALSE;
 		memset ((void *)out_file, 0, BUFSIZ);
-		strcpy(ps_file,ps_names[k]);
+		if (ps_file != ps_names[k]) strcpy(ps_file,ps_names[k]);
 		if ((fp = fopen (ps_file, "r")) == NULL) {
 			fprintf (stderr, "%s: Cannot to open file %s\n", GMT_program, ps_file);
 			continue;
