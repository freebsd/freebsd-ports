
$FreeBSD$

--- src/compare.c	2002/06/01 21:08:46	1.1
+++ src/compare.c	2002/06/01 21:09:16
@@ -565,7 +565,7 @@
 	size_t len = strlen (current_link_name);
 	char *linkbuf = alloca (len + 1);
 
-	status = readlink (current_file_name, linkbuf, len + 1);
+	status = readlink (current_file_name, linkbuf, len);
 
 	if (status < 0)
 	  {
