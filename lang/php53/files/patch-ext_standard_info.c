--- ext/standard/info.c.orig	2014-07-06 14:16:21.785793323 +0200
+++ ext/standard/info.c	2014-07-06 14:20:20.630549152 +0200
@@ -999,16 +999,16 @@
 
 		php_info_print_table_start();
 		php_info_print_table_header(2, "Variable", "Value");
-		if (zend_hash_find(&EG(symbol_table), "PHP_SELF", sizeof("PHP_SELF"), (void **) &data) != FAILURE) {
+		if (zend_hash_find(&EG(symbol_table), "PHP_SELF", sizeof("PHP_SELF"), (void **) &data) != FAILURE && Z_TYPE_PP(data) == IS_STRING) {
 			php_info_print_table_row(2, "PHP_SELF", Z_STRVAL_PP(data));
 		}
-		if (zend_hash_find(&EG(symbol_table), "PHP_AUTH_TYPE", sizeof("PHP_AUTH_TYPE"), (void **) &data) != FAILURE) {
+		if (zend_hash_find(&EG(symbol_table), "PHP_AUTH_TYPE", sizeof("PHP_AUTH_TYPE"), (void **) &data) != FAILURE && Z_TYPE_PP(data) == IS_STRING) {
 			php_info_print_table_row(2, "PHP_AUTH_TYPE", Z_STRVAL_PP(data));
 		}
-		if (zend_hash_find(&EG(symbol_table), "PHP_AUTH_USER", sizeof("PHP_AUTH_USER"), (void **) &data) != FAILURE) {
+		if (zend_hash_find(&EG(symbol_table), "PHP_AUTH_USER", sizeof("PHP_AUTH_USER"), (void **) &data) != FAILURE && Z_TYPE_PP(data) == IS_STRING) {
 			php_info_print_table_row(2, "PHP_AUTH_USER", Z_STRVAL_PP(data));
 		}
-		if (zend_hash_find(&EG(symbol_table), "PHP_AUTH_PW", sizeof("PHP_AUTH_PW"), (void **) &data) != FAILURE) {
+		if (zend_hash_find(&EG(symbol_table), "PHP_AUTH_PW", sizeof("PHP_AUTH_PW"), (void **) &data) != FAILURE && Z_TYPE_PP(data) == IS_STRING) {
 			php_info_print_table_row(2, "PHP_AUTH_PW", Z_STRVAL_PP(data));
 		}
 		php_print_gpcse_array("_REQUEST", sizeof("_REQUEST")-1 TSRMLS_CC);
