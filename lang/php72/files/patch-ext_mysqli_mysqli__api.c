--- ext/mysqli/mysqli_api.c.orig	2020-01-07 10:40:30 UTC
+++ ext/mysqli/mysqli_api.c
@@ -33,8 +33,9 @@
 #include "zend_smart_str.h"
 #include "php_mysqli_structs.h"
 #include "mysqli_priv.h"
+#if defined(MYSQLI_USE_MYSQLND)
 #include "ext/mysqlnd/mysql_float_to_double.h"
-
+#endif
 
 #if !defined(MYSQLI_USE_MYSQLND)
 /* {{{ mysqli_tx_cor_options_to_string */
