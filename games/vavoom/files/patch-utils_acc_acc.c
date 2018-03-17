--- utils/acc/acc.c.orig	2018-03-17 07:31:45.763803000 +0100
+++ utils/acc/acc.c	2018-03-17 07:34:25.591067000 +0100
@@ -120,7 +120,7 @@
 	fprintf(stderr, "\nOriginal ACC Version 1.10 by Ben Gokey\n");
 	fprintf(stderr, "Copyright (c) "COPYRIGHT_YEARS_TEXT
 		" Raven Software, Corp.\n\n");
-	fprintf(stderr, "This is version "VERSION_TEXT" ("__DATE__")\n");
+	fprintf(stderr, "This is version "VERSION_TEXT" (" __DATE__ ")\n");
 	fprintf(stderr, "This software is not supported by Raven Software or Activision\n");
 	fprintf(stderr, "ZDoom changes and language extensions by Randy Heit\n");
 	fprintf(stderr, "Further changes by Brad Carney\n");
