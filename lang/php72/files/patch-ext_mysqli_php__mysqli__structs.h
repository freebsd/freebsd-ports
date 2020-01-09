--- ext/mysqli/php_mysqli_structs.h.orig	2020-01-07 11:18:11 UTC
+++ ext/mysqli/php_mysqli_structs.h
@@ -38,7 +38,7 @@
 #define FALSE 0
 #endif
 
-#ifdef MYSQLI_USE_MYSQLND
+#if defined(MYSQLI_USE_MYSQLND)
 #include "ext/mysqlnd/mysqlnd.h"
 #include "mysqli_mysqlnd.h"
 #else
