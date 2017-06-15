--- libmariadb/ma_secure.c.orig	2016-08-03 15:39:12 UTC
+++ libmariadb/ma_secure.c
@@ -74,7 +74,7 @@ static void my_SSL_error(MYSQL *mysql)
    Crypto call back functions will be
    set during ssl_initialization
  */
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER)
 #if (OPENSSL_VERSION_NUMBER < 0x10000000) 
 static unsigned long my_cb_threadid(void)
 {
@@ -149,11 +149,11 @@ int my_ssl_start(MYSQL *mysql)
   pthread_mutex_lock(&LOCK_ssl_config);
   if (!my_ssl_initialized)
   {
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     if (ssl_crypto_init())
       goto end;
 #endif
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER) 
     OPENSSL_init_ssl(OPENSSL_INIT_LOAD_CONFIG, NULL);
 #else
     SSL_library_init();
