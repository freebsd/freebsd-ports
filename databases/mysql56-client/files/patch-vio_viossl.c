--- vio/viossl.c.orig	2019-11-26 16:53:45 UTC
+++ vio/viossl.c
@@ -385,7 +385,7 @@ static int ssl_do(struct st_VioSSLFd *ptr, Vio *vio,
   DBUG_PRINT("info", ("ssl: 0x%lx timeout: %ld", (long) ssl, timeout));
   SSL_clear(ssl);
   SSL_set_fd(ssl, sd);
-#if defined(SSL_OP_NO_COMPRESSION)
+#if defined(SSL_OP_NO_COMPRESSION) && !defined(LIBRESSL_VERSION_NUMBER)
   SSL_set_options(ssl, SSL_OP_NO_COMPRESSION); /* OpenSSL >= 1.0 only */
 #elif OPENSSL_VERSION_NUMBER >= 0x00908000L /* workaround for OpenSSL 0.9.8 */
   sk_SSL_COMP_zero(SSL_COMP_get_compression_methods());
@@ -403,7 +403,7 @@ static int ssl_do(struct st_VioSSLFd *ptr, Vio *vio,
       for (j = 0; j < n; j++)
       {
         SSL_COMP *c = sk_SSL_COMP_value(ssl_comp_methods, j);
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
         DBUG_PRINT("info", ("  %d: %s\n", c->id, c->name));
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
         DBUG_PRINT("info", ("  %d: %s\n", SSL_COMP_get_id(c), SSL_COMP_get0_name(c)));
