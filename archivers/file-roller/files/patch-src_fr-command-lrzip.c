--- src/fr-command-lrzip.c.orig	2010-08-26 12:40:56.000000000 -0400
+++ src/fr-command-lrzip.c	2010-08-26 12:41:41.000000000 -0400
@@ -53,7 +53,7 @@ list__process_line (char     *line,
 	struct stat st;
 	time_t tt;
 	if (stat (comm->filename, &st) == 0)
-		fdata->modified = st.st_mtim.tv_sec;
+		fdata->modified = st.st_mtime;
 	else
 		time(&(fdata->modified));
 	fdata->modified;
