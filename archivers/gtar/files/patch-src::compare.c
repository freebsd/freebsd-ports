
$FreeBSD$

--- src/compare.c.orig	Sun Apr  4 11:53:30 2004
+++ src/compare.c	Thu Apr 22 17:50:16 2004
@@ -327,7 +327,7 @@
 	size_t len = strlen (current_stat_info.link_name);
 	char *linkbuf = alloca (len + 1);
 
-	status = readlink (current_stat_info.file_name, linkbuf, len + 1);
+	status = readlink (current_stat_info.file_name, linkbuf, len);
 
 	if (status < 0)
 	  {
