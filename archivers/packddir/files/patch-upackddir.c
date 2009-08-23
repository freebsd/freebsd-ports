--- upackddir.c.orig	2009-08-22 04:48:16.000000000 +0900
+++ upackddir.c	2009-08-22 04:48:39.000000000 +0900
@@ -253,7 +253,7 @@
 	}
 
 	/* Let's jump to the beginning of our sweet data */
-	(char *) mapped += n;
+	mapped += n;
 
 	for (i = 0; i < pack->numfiles; i++) {
 		fprintf(stderr, "%s\n", mapped->name);
@@ -297,7 +297,7 @@
 	}
 
 	/* Let's jump to the beginning of our sweet data */
-	(char *) mapped += n;
+	mapped += n;
 
 	for (i = 0; i < pack->numfiles; i++) {
 		if (strcmp(name, mapped->name) == 0) {
