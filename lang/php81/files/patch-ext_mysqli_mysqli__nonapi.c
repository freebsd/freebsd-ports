--- ext/mysqli/mysqli_nonapi.c.orig	2020-01-09 11:40:57 UTC
+++ ext/mysqli/mysqli_nonapi.c
@@ -28,7 +28,9 @@
 #include "php_ini.h"
 #include "ext/standard/info.h"
 #include "zend_smart_str.h"
+#if defined(MYSQLI_USE_MYSQLND)
 #include "php_mysqli_structs.h"
+#endif
 #include "mysqli_priv.h"
 
 #define SAFE_STR(a) ((a)?a:"")
