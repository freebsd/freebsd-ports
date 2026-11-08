--- src/php7/igbinary.c.orig	2026-08-16 05:00:40 UTC
+++ src/php7/igbinary.c
@@ -28,7 +28,7 @@
 #include "Zend/zend_enum.h"
 #endif
 
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 # include "ext/session/php_session.h"
 #endif
 
@@ -69,10 +69,10 @@
 #include "zend_alloc.h"
 #include "igbinary_zend_hash.h"
 
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 /** Session serializer function prototypes. */
 PS_SERIALIZER_FUNCS(igbinary);
-#endif /* HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION) */
+#endif /* HAVE_PHP_SESSION */
 
 #if defined(HAVE_APCU_SUPPORT)
 /** Apc serializer function prototypes */
@@ -353,7 +353,7 @@ static const zend_module_dep igbinary_module_deps[] = 
 /* {{{ igbinary dependencies */
 static const zend_module_dep igbinary_module_deps[] = {
 	ZEND_MOD_REQUIRED("standard")
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 	ZEND_MOD_REQUIRED("session")
 #endif
 #if defined(HAVE_APCU_SUPPORT)
@@ -409,7 +409,7 @@ PHP_MINIT_FUNCTION(igbinary) {
 	(void)module_number;
 	ZEND_INIT_MODULE_GLOBALS(igbinary, php_igbinary_init_globals, NULL);
 
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 	php_session_register_serializer("igbinary",
 		PS_SERIALIZER_ENCODE_NAME(igbinary),
 		PS_SERIALIZER_DECODE_NAME(igbinary));
@@ -460,7 +460,7 @@ PHP_MINFO_FUNCTION(igbinary) {
 #else
 	php_info_print_table_row(2, "igbinary APCu serializer ABI", "no");
 #endif
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 	php_info_print_table_row(2, "igbinary session support", "yes");
 #else
 	php_info_print_table_row(2, "igbinary session support", "no");
@@ -855,7 +855,7 @@ PHP_FUNCTION(igbinary_serialize) {
 	efree(string);
 }
 /* }}} */
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 /* {{{ Serializer encode function */
 /**
  * This provides a serializer encode function for PHP's session module (using igbinary),
@@ -974,7 +974,7 @@ deinit:
 	return SUCCESS;
 }
 /* }}} */
-#endif /* HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION) */
+#endif /* HAVE_PHP_SESSION */
 
 #if defined(HAVE_APCU_SUPPORT)
 /* {{{ apc_serialize function */
