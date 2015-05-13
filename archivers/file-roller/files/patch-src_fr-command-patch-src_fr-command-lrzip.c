--- src/fr-command-lrzip.c.orig	2014-08-12 22:21:20.000000000 -0700
+++ src/fr-command-lrzip.c	2014-12-02 23:31:58.000000000 -0800
@@ -45,7 +45,11 @@
 
 	struct stat st;
 	if (stat (comm->filename, &st) == 0)
+#if __FreeBSD_version < 900011
+		fdata->modified = st.st_mtimespec.tv_sec;
+#else
 		fdata->modified = st.st_mtim.tv_sec;
+#endif
 	else
 		time(&(fdata->modified));
 
