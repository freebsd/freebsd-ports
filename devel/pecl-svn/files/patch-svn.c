--- svn.c.orig	2010-12-09 04:30:16.000000000 +0100
+++ svn.c	2012-02-28 09:46:50.877059221 +0100
@@ -34,6 +34,7 @@
 
 #include "apr_version.h"
 #include "svn_pools.h"
+#include "svn_props.h"
 #include "svn_sorts.h"
 #include "svn_config.h"
 #include "svn_auth.h"
@@ -43,6 +44,7 @@
 #include "svn_utf.h"
 #include "svn_time.h"
 #include "svn_props.h"
+#include "svn_version.h"
 
 ZEND_DECLARE_MODULE_GLOBALS(svn)
 
@@ -96,7 +98,13 @@
 static ZEND_RSRC_DTOR_FUNC(php_svn_repos_dtor)
 {
 	struct php_svn_repos *r = rsrc->ptr;
-	svn_pool_destroy(r->pool);
+	/*
+	 * If root pool doesn't exist, then this resource's pool was already
+	 * destroyed
+	 */
+	if (SVN_G(pool)) {
+		svn_pool_destroy(r->pool);
+	}
 	efree(r);
 }
 
@@ -123,7 +131,7 @@
 
 #define SVN_STATIC_ME(name) ZEND_FENTRY(name, ZEND_FN(svn_ ## name), NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
 /** Fixme = this list needs padding out... */
-static function_entry svn_methods[] = {
+static zend_function_entry svn_methods[] = {
 	SVN_STATIC_ME(cat)
 	SVN_STATIC_ME(checkout)
 	SVN_STATIC_ME(log)
@@ -134,7 +142,7 @@
 
 
 /* {{{ svn_functions[] */
-function_entry svn_functions[] = {
+zend_function_entry svn_functions[] = {
 	PHP_FE(svn_checkout,		NULL)
 	PHP_FE(svn_cat,			NULL)
 	PHP_FE(svn_ls,			NULL)
@@ -270,7 +278,7 @@
 
 	smart_str_appendl(&s, "\n", 1);
 	smart_str_0(&s);
-	php_error_docref(NULL TSRMLS_CC, E_WARNING, s.c);
+	php_error_docref(NULL TSRMLS_CC, E_WARNING, "%s", s.c);
 	smart_str_free(&s);
 }
 
