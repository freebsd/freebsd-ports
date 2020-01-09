--- ext/mysqli/mysqli_api.c.orig	2019-12-17 10:29:23 UTC
+++ ext/mysqli/mysqli_api.c
@@ -31,8 +31,9 @@
 #include "zend_smart_str.h"
 #include "php_mysqli_structs.h"
 #include "mysqli_priv.h"
+#if defined(MYSQLI_USE_MYSQLND)
 #include "ext/mysqlnd/mysql_float_to_double.h"
-
+#endif
 
 #if !defined(MYSQLI_USE_MYSQLND)
 /* {{{ mysqli_tx_cor_options_to_string */
