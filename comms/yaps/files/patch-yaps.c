--- yaps.c.orig	1997-06-14 10:25:56 UTC
+++ yaps.c
@@ -1177,7 +1177,7 @@ create_messages (void *cfg, char *servic
 			fprintf (stderr, "Unable to open message file %s for reading\n", mfile);
 			return NULL;
 		}
-		while (ptr = getline (fp, False)) {
+		while (ptr = get_line (fp, False)) {
 			sav = skip (ptr);
 			if (*ptr && *sav) {
 				if (rcnt + 2 >= rsiz) {
