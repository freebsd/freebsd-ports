--- sql/mysqld.cc.orig	2022-07-06 21:36:34 UTC
+++ sql/mysqld.cc
@@ -5299,7 +5299,7 @@ static int init_thread_environment() {
 
 static PSI_memory_key key_memory_openssl = PSI_NOT_INSTRUMENTED;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #define FILE_LINE_ARGS
 #else
 #define FILE_LINE_ARGS , const char *, int
