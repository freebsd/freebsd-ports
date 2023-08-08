--- utils/acc/acc.c.orig	2022-12-31 03:37:54 UTC
+++ utils/acc/acc.c
@@ -120,7 +120,7 @@ static void DisplayBanner(void)
 	fprintf(stderr, "\nOriginal ACC Version 1.10 by Ben Gokey\n");
 	fprintf(stderr, "Copyright (c) "COPYRIGHT_YEARS_TEXT
 		" Raven Software, Corp.\n\n");
-	fprintf(stderr, "This is version "VERSION_TEXT" ("__DATE__")\n");
+	fprintf(stderr, "This is version "VERSION_TEXT" (" __DATE__ ")\n");
 	fprintf(stderr, "This software is not supported by Raven Software or Activision\n");
 	fprintf(stderr, "ZDoom changes and language extensions by Randy Heit\n");
 	fprintf(stderr, "Further changes by Brad Carney\n");
