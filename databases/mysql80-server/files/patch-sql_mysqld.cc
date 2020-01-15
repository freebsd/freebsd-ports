--- sql/mysqld.cc.orig	2019-09-20 08:30:51 UTC
+++ sql/mysqld.cc
@@ -4818,7 +4818,7 @@ static int init_thread_environment() {
 
 static PSI_memory_key key_memory_openssl = PSI_NOT_INSTRUMENTED;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #define FILE_LINE_ARGS
 #else
 #define FILE_LINE_ARGS , const char *, int
@@ -4854,12 +4854,14 @@ static void init_ssl() {
 }
 
 static int init_ssl_communication() {
+#ifndef LIBRESSL_VERSION_NUMBER
   char ssl_err_string[OPENSSL_ERROR_LENGTH] = {'\0'};
   int ret_fips_mode = set_fips_mode(opt_ssl_fips_mode, ssl_err_string);
   if (ret_fips_mode != 1) {
     LogErr(ERROR_LEVEL, ER_SSL_FIPS_MODE_ERROR, ssl_err_string);
     return 1;
   }
+#endif /* LIBRESSL_VERSION_NUMBER */
   if (SslAcceptorContext::singleton_init(opt_use_ssl)) return 1;
 
 #if OPENSSL_VERSION_NUMBER < 0x10100000L
