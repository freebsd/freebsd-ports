CVE-2006-2656
===================================================================
--- tools/tiffsplit.c.orig	2008-08-17 13:03:49.014994263 -0400
+++ tools/tiffsplit.c	2008-08-17 13:03:52.726994578 -0400
@@ -61,14 +61,13 @@
 		return (-3);
 	}
 	if (argc > 2)
-		strcpy(fname, argv[2]);
+		snprintf(fname, sizeof(fname), "%s", argv[2]);
 	in = TIFFOpen(argv[1], "r");
 	if (in != NULL) {
 		do {
 			char path[1024+1];
 			newfilename();
-			strcpy(path, fname);
-			strcat(path, ".tif");
+			snprintf(path, sizeof(path), "%s.tif", fname);
 			out = TIFFOpen(path, TIFFIsBigEndian(in)?"wb":"wl");
 			if (out == NULL)
 				return (-2);
