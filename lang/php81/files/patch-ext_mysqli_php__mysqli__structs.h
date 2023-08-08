--- ext/mysqli/php_mysqli_structs.h.orig	2023-03-14 19:50:20 UTC
+++ ext/mysqli/php_mysqli_structs.h
@@ -26,7 +26,7 @@
 #undef LIST
 #endif
 
-#ifdef MYSQLI_USE_MYSQLND
+#if defined(MYSQLI_USE_MYSQLND)
 #include "ext/mysqlnd/mysqlnd.h"
 #include "mysqli_mysqlnd.h"
 #else
