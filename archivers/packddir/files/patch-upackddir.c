--- upackddir.c.orig	2004-01-17 12:08:52 UTC
+++ upackddir.c
@@ -253,7 +253,7 @@ int packfile_extract(char *packfile, int
 	}
 
 	/* Let's jump to the beginning of our sweet data */
-	(char *) mapped += n;
+	mapped += n;
 
 	for (i = 0; i < pack->numfiles; i++) {
 		fprintf(stderr, "%s\n", mapped->name);
@@ -297,7 +297,7 @@ int packfile_extract_filename(char *pack
 	}
 
 	/* Let's jump to the beginning of our sweet data */
-	(char *) mapped += n;
+	mapped += n;
 
 	for (i = 0; i < pack->numfiles; i++) {
 		if (strcmp(name, mapped->name) == 0) {
