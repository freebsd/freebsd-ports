--- sql/mysqld.cc.orig	2019-09-20 08:30:51 UTC
+++ sql/mysqld.cc
@@ -4797,7 +4797,7 @@ static int init_thread_environment() {
 
 static PSI_memory_key key_memory_openssl = PSI_NOT_INSTRUMENTED;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #define FILE_LINE_ARGS
 #else
 #define FILE_LINE_ARGS , const char *, int
