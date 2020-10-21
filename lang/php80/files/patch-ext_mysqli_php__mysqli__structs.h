--- ext/mysqli/php_mysqli_structs.h.orig	2019-12-17 10:29:23 UTC
+++ ext/mysqli/php_mysqli_structs.h
@@ -36,7 +36,7 @@
 #define FALSE 0
 #endif
 
-#ifdef MYSQLI_USE_MYSQLND
+#if defined(MYSQLI_USE_MYSQLND)
 #include "ext/mysqlnd/mysqlnd.h"
 #include "mysqli_mysqlnd.h"
 #else
