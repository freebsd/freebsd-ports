diff -ruN main/fopen_wrappers.c main/fopen_wrappers.c.orig
--- main/fopen_wrappers.c.orig	2010-12-09 18:04:29.000000000 +0100
+++ main/fopen_wrappers.c	2010-12-10 11:32:02.000000000 +0100
@@ -192,7 +192,7 @@
 		if (strncmp(resolved_basedir, resolved_name, resolved_basedir_len) == 0) {
 #endif
 			if (resolved_name_len > resolved_basedir_len &&
-				resolved_name[resolved_basedir_len] != PHP_DIR_SEPARATOR) {
+				resolved_name[resolved_basedir_len - 1] != PHP_DIR_SEPARATOR) {
 				return -1;
 			} else {
 				/* File is in the right directory */
