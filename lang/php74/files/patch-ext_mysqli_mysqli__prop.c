--- ext/mysqli/mysqli_prop.c.orig	2020-01-09 11:40:11 UTC
+++ ext/mysqli/mysqli_prop.c
@@ -26,7 +26,9 @@
 #include "php.h"
 #include "php_ini.h"
 #include "ext/standard/info.h"
+#if defined(MYSQLI_USE_MYSQLND)
 #include "php_mysqli_structs.h"
+#endif
 #include "mysqli_priv.h"
 
 #define CHECK_STATUS(value) \
