--- ext/pcre/php_pcre.c.orig	Fri Apr 16 09:21:14 2004
+++ ext/pcre/php_pcre.c	Fri Apr 16 09:23:36 2004
@@ -106,15 +106,6 @@
 	REGISTER_LONG_CONSTANT("PREG_SPLIT_DELIM_CAPTURE", PREG_SPLIT_DELIM_CAPTURE, CONST_CS | CONST_PERSISTENT);
 	REGISTER_LONG_CONSTANT("PREG_SPLIT_OFFSET_CAPTURE", PREG_SPLIT_OFFSET_CAPTURE, CONST_CS | CONST_PERSISTENT);
 	REGISTER_LONG_CONSTANT("PREG_GREP_INVERT", PREG_GREP_INVERT, CONST_CS | CONST_PERSISTENT);
-
-	pcre_malloc = php_pcre_malloc;
-	pcre_free = php_pcre_free;
-
-#ifdef NO_RECURSE
-	pcre_stack_malloc = php_pcre_malloc;
-	pcre_stack_free = php_pcre_free;
-#endif
-	
 	return SUCCESS;
 }
 /* }}} */
@@ -130,6 +121,16 @@
 }
 /* }}} */
 
+/* {{{ PHP_RINIT_FUNCTION(pcre) */
+static PHP_RINIT_FUNCTION(pcre)
+{
+	pcre_malloc = php_pcre_malloc;
+	pcre_free = php_pcre_free;
+
+	return SUCCESS;
+}
+/* }}} */
+
 /* {{{ pcre_get_compiled_regex
  */
 PHPAPI pcre* pcre_get_compiled_regex(char *regex, pcre_extra **extra, int *preg_options) {
@@ -1527,7 +1528,7 @@
 	pcre_functions,
 	PHP_MINIT(pcre),
 	PHP_MSHUTDOWN(pcre),
-	NULL,
+	PHP_RINIT(pcre),
 	NULL,
 	PHP_MINFO(pcre),
 	NO_VERSION_YET,
