--- ext/mysqli/mysqli_api.c.orig	2020-09-29 22:36:51 UTC
+++ ext/mysqli/mysqli_api.c
@@ -29,7 +29,9 @@
 #include "zend_smart_str.h"
 #include "php_mysqli_structs.h"
 #include "mysqli_priv.h"
+#if defined(MYSQLI_USE_MYSQLND)
 #include "ext/mysqlnd/mysql_float_to_double.h"
+#endif
 
 #define ERROR_ARG_POS(arg_num) (getThis() ? (arg_num-1) : (arg_num))
 
