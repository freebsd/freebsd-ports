--- sql/mysqld.cc.orig	2019-11-26 16:53:45 UTC
+++ sql/mysqld.cc
@@ -1258,7 +1258,7 @@ char *opt_ssl_ca= NULL, *opt_ssl_capath= NULL, *opt_ss
      *opt_ssl_crlpath= NULL;
 
 #ifdef HAVE_OPENSSL
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #include <openssl/crypto.h>
 typedef struct CRYPTO_dynlock_value
 {
@@ -2029,7 +2029,7 @@ static void clean_up_mutexes()
   mysql_mutex_destroy(&LOCK_connection_count);
 #ifdef HAVE_OPENSSL
   mysql_mutex_destroy(&LOCK_des_key_file);
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   for (int i= 0; i < CRYPTO_num_locks(); ++i)
     mysql_rwlock_destroy(&openssl_stdlocks[i].lock);
   OPENSSL_free(openssl_stdlocks);
@@ -2768,7 +2768,7 @@ bool one_thread_per_connection_end(THD *thd, bool bloc
 
   // Clean up errors now, before possibly waiting for a new connection.
 #ifndef EMBEDDED_LIBRARY
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   ERR_remove_thread_state(0);
 #endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
 #endif
@@ -4252,7 +4252,7 @@ static int init_thread_environment()
 #ifdef HAVE_OPENSSL
   mysql_mutex_init(key_LOCK_des_key_file,
                    &LOCK_des_key_file, MY_MUTEX_INIT_FAST);
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   openssl_stdlocks= (openssl_lock_t*) OPENSSL_malloc(CRYPTO_num_locks() *
                                                      sizeof(openssl_lock_t));
   for (int i= 0; i < CRYPTO_num_locks(); ++i)
@@ -4301,7 +4301,7 @@ static int init_thread_environment()
   OpenSSL 1.1 supports native platform threads,
   so we don't need the following callback functions.
 */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
 static unsigned long openssl_id_function()
 {
@@ -4375,7 +4375,7 @@ static void openssl_lock(int mode, openssl_lock_t *loc
 static int init_ssl()
 {
 #ifdef HAVE_OPENSSL
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   CRYPTO_malloc_init();
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   OPENSSL_malloc_init();
@@ -4392,7 +4392,7 @@ static int init_ssl()
 					  opt_ssl_cipher, &error,
                                           opt_ssl_crl, opt_ssl_crlpath);
     DBUG_PRINT("info",("ssl_acceptor_fd: 0x%lx", (long) ssl_acceptor_fd));
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     ERR_remove_thread_state(0);
 #endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
     if (!ssl_acceptor_fd)
