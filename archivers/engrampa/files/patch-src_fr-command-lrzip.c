--- src/fr-command-lrzip.c.orig	2015-10-14 17:33:41 UTC
+++ src/fr-command-lrzip.c
@@ -53,7 +53,7 @@ list__process_line (char     *line,
 	struct stat st;
 	
 	if (stat (comm->filename, &st) == 0)
-		fdata->modified = st.st_mtim.tv_sec;
+		fdata->modified = st.st_mtime;
 	else
 		time(&(fdata->modified));
 
