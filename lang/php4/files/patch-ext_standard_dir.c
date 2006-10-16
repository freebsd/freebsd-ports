--- ext/standard/dir.c.orig	Mon Oct 16 06:59:56 2006
+++ ext/standard/dir.c	Mon Oct 16 07:00:06 2006
@@ -16,7 +16,7 @@
    +----------------------------------------------------------------------+
  */
 
-/* $Id: dir.c,v 1.109.2.18.2.2 2006/01/01 13:46:57 sniper Exp $ */
+/* $Id: dir.c,v 1.109.2.18.2.3 2006/10/04 23:20:02 iliaa Exp $ */
 
 /* {{{ includes/startup/misc */
 
@@ -275,7 +275,7 @@
 		RETURN_FALSE;
 	}
 
-	if (PG(safe_mode) && !php_checkuid(str, NULL, CHECKUID_CHECK_FILE_AND_DIR)) {
+	if ((PG(safe_mode) && !php_checkuid(str, NULL, CHECKUID_CHECK_FILE_AND_DIR)) || php_check_open_basedir(str TSRMLS_CC)) {
 		RETURN_FALSE;
 	}
 	ret = VCWD_CHDIR(str);
