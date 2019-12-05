--- sql/mysqld.cc.orig	2019-09-27 09:00:15.000000000 +0200
+++ sql/mysqld.cc	2019-11-24 17:47:52.395539000 +0100
@@ -3419,7 +3419,7 @@
 static int init_ssl()
 {
 #ifdef HAVE_OPENSSL
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   CRYPTO_malloc_init();
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   OPENSSL_malloc_init();
