--- arcadd.c.orig	2013-06-27 02:00:19 UTC
+++ arcadd.c
@@ -117,7 +117,7 @@ int             fresh;		/* true if freshening */
 			}
 #endif
 		}
-		if (notemp && warn)
+		if (notemp && arcwarn)
 			printf("No files match: %s\n", arg[n]);
 	}
 
@@ -131,7 +131,7 @@ int             fresh;		/* true if freshening */
 		free(path);
 		free(name);
 	}
-	if (nowork && warn)
+	if (nowork && arcwarn)
 		printf("No files were added.\n");
 }
 
@@ -225,7 +225,7 @@ addbunch(nfiles, path, name, move, update, fresh)	/* a
 	if (move) {		/* if this was a move */
 		for (n = 0; n < nfiles; n++) {	/* then delete each file
 						 * added */
-			if (unlink(path[n]) && warn) {
+			if (unlink(path[n]) && arcwarn) {
 				printf("Cannot unsave %s\n", path[n]);
 				nerrs++;
 			}
@@ -257,7 +257,7 @@ addfile(path, name, update, fresh)	/* add named file t
 	if (!f)
 #endif
 	{
-		if (warn) {
+		if (arcwarn) {
 			printf("Cannot read file: %s\n", path);
 			nerrs++;
 		}
@@ -265,7 +265,7 @@ addfile(path, name, update, fresh)	/* add named file t
 	}
 #if	!DOS
 	if (strlen(name) >= FNLEN) {
-		if (warn) {
+		if (arcwarn) {
 			char	buf[STRLEN];
 			printf("WARNING: File %s name too long!\n", name);
 			name[FNLEN-1]='\0';
