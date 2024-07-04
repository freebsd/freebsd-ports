--- ext/mysqli/php_mysqli_structs.h.orig	2023-06-07 17:25:45 UTC
+++ ext/mysqli/php_mysqli_structs.h
@@ -34,7 +34,7 @@
 #define FALSE 0
 #endif
 
-#ifdef MYSQLI_USE_MYSQLND
+#if defined(MYSQLI_USE_MYSQLND)
 #include "ext/mysqlnd/mysqlnd.h"
 #include "mysqli_mysqlnd.h"
 #else
