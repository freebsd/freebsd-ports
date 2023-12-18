--- sql/mysqld.cc.orig	2023-06-21 07:52:10 UTC
+++ sql/mysqld.cc
@@ -5428,7 +5428,7 @@ static PSI_memory_key key_memory_openssl = PSI_NOT_INS
 
 static PSI_memory_key key_memory_openssl = PSI_NOT_INSTRUMENTED;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #define FILE_LINE_ARGS
 #else
 #define FILE_LINE_ARGS , const char *, int
