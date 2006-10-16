--- ext/standard/dir.c.orig	Mon Oct 16 07:08:36 2006
+++ ext/standard/dir.c	Mon Oct 16 07:08:40 2006
@@ -16,7 +16,7 @@
    +----------------------------------------------------------------------+
  */
 
-/* $Id: dir.c,v 1.147.2.3 2006/02/26 10:49:50 helly Exp $ */
+/* $Id: dir.c,v 1.147.2.3.2.1 2006/10/04 23:19:25 iliaa Exp $ */
 
 /* {{{ includes/startup/misc */
 
@@ -286,7 +286,7 @@
 		RETURN_FALSE;
 	}
 
-	if (PG(safe_mode) && !php_checkuid(str, NULL, CHECKUID_CHECK_FILE_AND_DIR)) {
+	if ((PG(safe_mode) && !php_checkuid(str, NULL, CHECKUID_CHECK_FILE_AND_DIR)) || php_check_open_basedir(str TSRMLS_CC)) {
 		RETURN_FALSE;
 	}
 	ret = VCWD_CHDIR(str);
