--- config.h.orig	2017-10-24 17:27:46 UTC
+++ config.h
@@ -4,4 +4,12 @@
 #define VERSION "0.9.3"
 /* #undef WITH_BINLOG */
 
+#if   defined(LIBMYSQL_VERSION)
+#define MYSQL_VERSION_STR LIBMYSQL_VERSION
+#elif defined(MARIADB_CLIENT_VERSION_STR)
+#define MYSQL_VERSION_STR MARIADB_CLIENT_VERSION_STR
+#else
+#define MYSQL_VERSION_STR MYSQL_VERSION_NUMBER
+#endif
+
 #endif
