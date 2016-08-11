--- arcadd.c.orig	2010-08-07 13:06:42 UTC
+++ arcadd.c
@@ -119,7 +119,7 @@ int             fresh;		/* true if fresh
 			}
 #endif
 		}
-		if (notemp && warn)
+		if (notemp && arcwarn)
 			printf("No files match: %s\n", arg[n]);
 	}
 
@@ -133,7 +133,7 @@ int             fresh;		/* true if fresh
 		free(path);
 		free(name);
 	}
-	if (nowork && warn)
+	if (nowork && arcwarn)
 		printf("No files were added.\n");
 }
 
@@ -227,7 +227,7 @@ addbunch(nfiles, path, name, move, updat
 	if (move) {		/* if this was a move */
 		for (n = 0; n < nfiles; n++) {	/* then delete each file
 						 * added */
-			if (unlink(path[n]) && warn) {
+			if (unlink(path[n]) && arcwarn) {
 				printf("Cannot unsave %s\n", path[n]);
 				nerrs++;
 			}
@@ -259,7 +259,7 @@ addfile(path, name, update, fresh)	/* ad
 	if (!f)
 #endif
 	{
-		if (warn) {
+		if (arcwarn) {
 			printf("Cannot read file: %s\n", path);
 			nerrs++;
 		}
@@ -267,7 +267,7 @@ addfile(path, name, update, fresh)	/* ad
 	}
 #if	!DOS
 	if (strlen(name) >= FNLEN) {
-		if (warn) {
+		if (arcwarn) {
 			char	buf[STRLEN];
 			printf("WARNING: File %s name too long!\n", name);
 			name[FNLEN-1]='\0';
