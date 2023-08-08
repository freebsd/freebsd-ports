--- ext/mysqli/mysqli_prop.c.orig	2023-06-07 17:25:45 UTC
+++ ext/mysqli/mysqli_prop.c
@@ -24,7 +24,9 @@
 #include "php.h"
 #include "php_ini.h"
 #include "ext/standard/info.h"
+#if defined(MYSQLI_USE_MYSQLND)
 #include "php_mysqli_structs.h"
+#endif
 #include "mysqli_priv.h"
 
 #define CHECK_STATUS(value, quiet) \
