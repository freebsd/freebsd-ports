--- libmariadb/ma_secure.c.orig	2017-01-17 09:53:54 UTC
+++ libmariadb/ma_secure.c
@@ -149,11 +149,11 @@ int my_ssl_start(MYSQL *mysql)
   pthread_mutex_lock(&LOCK_ssl_config);
   if (!my_ssl_initialized)
   {
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER)
     if (ssl_crypto_init())
       goto end;
 #endif
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     OPENSSL_init_ssl(OPENSSL_INIT_LOAD_CONFIG, NULL);
 #else
     SSL_library_init();
