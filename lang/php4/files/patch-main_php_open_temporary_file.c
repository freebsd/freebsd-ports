--- main/php_open_temporary_file.c.orig	Mon Oct 16 07:26:57 2006
+++ main/php_open_temporary_file.c	Mon Oct 16 07:27:01 2006
@@ -16,7 +16,7 @@
    +----------------------------------------------------------------------+
  */
 
-/* $Id: php_open_temporary_file.c,v 1.18.2.10.2.3 2006/05/23 23:23:39 iliaa Exp $ */
+/* $Id: php_open_temporary_file.c,v 1.18.2.10.2.6 2006/10/13 01:12:11 iliaa Exp $ */
 
 #include "php.h"
 
@@ -207,6 +207,7 @@
 PHPAPI int php_open_temporary_fd(const char *dir, const char *pfx, char **opened_path_p TSRMLS_DC)
 {
 	int fd;
+	const char *temp_dir;
 
 	if (!pfx) {
 		pfx = "tmp.";
@@ -215,11 +216,22 @@
 		*opened_path_p = NULL;
 	}
 
+	if (!dir || *dir == '\0') {
+def_tmp:
+		temp_dir = php_get_temporary_directory();
+
+		if (temp_dir && *temp_dir != '\0' && !php_check_open_basedir(temp_dir TSRMLS_CC)) {
+			return php_do_open_temporary_file(temp_dir, pfx, opened_path_p TSRMLS_CC);
+		} else {
+			return -1;
+		}
+	}
+
 	/* Try the directory given as parameter. */
 	fd = php_do_open_temporary_file(dir, pfx, opened_path_p TSRMLS_CC);
 	if (fd == -1) {
 		/* Use default temporary directory. */
-		fd = php_do_open_temporary_file(php_get_temporary_directory(), pfx, opened_path_p TSRMLS_CC);
+		goto def_tmp;
 	}
 	return fd;
 }
