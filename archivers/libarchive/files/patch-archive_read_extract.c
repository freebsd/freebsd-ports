$FreeBSD$

--- archive_read_extract.c.orig	Mon Mar 14 10:12:52 2005
+++ archive_read_extract.c	Mon Mar 14 10:13:03 2005
@@ -188,12 +188,13 @@
 	 * and move to a suitable intermediate dir.
 	 */
 	if (strlen(archive_entry_pathname(entry)) > PATH_MAX) {
+		char *intdir, *tail;
+
 		/*
 		 * Yes, the copy here is necessary because we edit
 		 * the pathname in-place to create intermediate dirnames.
 		 */
 		original_filename = strdup(archive_entry_pathname(entry));
-		char *intdir, *tail;
 
 		restore_pwd = open(".", O_RDONLY);
 		/*
