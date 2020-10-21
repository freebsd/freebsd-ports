--- php_mysqli_structs.h.orig	2010-07-26 15:52:54.000000000 +0200
+++ php_mysqli_structs.h	2010-07-26 15:53:14.000000000 +0200
@@ -36,7 +36,7 @@
 #define FALSE 0
 #endif
 
-#ifdef MYSQLI_USE_MYSQLND
+#if defined(MYSQLI_USE_MYSQLND)
 #include "ext/mysqlnd/mysqlnd.h"
 #include "mysqli_mysqlnd.h"
 #else
@@ -53,6 +53,8 @@
 #undef HAVE_MBSTATE_T
 #define WE_HAD_MBSTATE_T
 #endif
+
+typedef zend_ulong ulong;
 
 #if defined(ulong) && !defined(HAVE_ULONG)
 #define HAVE_ULONG
