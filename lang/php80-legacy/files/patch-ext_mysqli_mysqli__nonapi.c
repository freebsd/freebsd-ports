--- ext/mysqli/mysqli_nonapi.c.orig	2023-06-07 17:25:45 UTC
+++ ext/mysqli/mysqli_nonapi.c
@@ -26,7 +26,9 @@
 #include "php_ini.h"
 #include "ext/standard/info.h"
 #include "zend_smart_str.h"
+#if defined(MYSQLI_USE_MYSQLND)
 #include "php_mysqli_structs.h"
+#endif
 #include "mysqli_priv.h"
 #define ERROR_ARG_POS(arg_num) (getThis() ? (arg_num-1) : (arg_num))
 
