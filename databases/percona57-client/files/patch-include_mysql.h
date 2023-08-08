--- include/mysql.h.orig	2023-02-28 17:21:35 UTC
+++ include/mysql.h
@@ -46,7 +46,10 @@ extern "C" {
 #ifndef MYSQL_ABI_CHECK
 #include <sys/types.h>
 #endif
+#ifndef HAVE_TYPE_MY_BOOL
+#define HAVE_TYPE_MY_BOOL
 typedef char my_bool;
+#endif
 #if !defined(_WIN32)
 #define STDCALL
 #else
