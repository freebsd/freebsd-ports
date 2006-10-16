--- main/php_open_temporary_file.c.orig	Mon Oct 16 07:21:14 2006
+++ main/php_open_temporary_file.c	Mon Oct 16 07:22:00 2006
@@ -16,7 +16,7 @@
    +----------------------------------------------------------------------+
  */
 
-/* $Id: php_open_temporary_file.c,v 1.34.2.2 2006/05/23 23:22:26 iliaa Exp $ */
+/* $Id: php_open_temporary_file.c,v 1.34.2.1.2.4 2006/10/13 01:11:30 iliaa Exp $ */
 
 #include "php.h"
 
@@ -206,6 +206,7 @@
 PHPAPI int php_open_temporary_fd(const char *dir, const char *pfx, char **opened_path_p TSRMLS_DC)
 {
 	int fd;
+	const char *temp_dir;
 
 	if (!pfx) {
 		pfx = "tmp.";
@@ -214,11 +215,22 @@
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
