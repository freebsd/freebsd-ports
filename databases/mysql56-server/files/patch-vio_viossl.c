--- vio/viossl.c.orig	2019-11-26 16:53:45 UTC
+++ vio/viossl.c
@@ -403,7 +403,7 @@ static int ssl_do(struct st_VioSSLFd *ptr, Vio *vio,
       for (j = 0; j < n; j++)
       {
         SSL_COMP *c = sk_SSL_COMP_value(ssl_comp_methods, j);
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
         DBUG_PRINT("info", ("  %d: %s\n", c->id, c->name));
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
         DBUG_PRINT("info", ("  %d: %s\n", SSL_COMP_get_id(c), SSL_COMP_get0_name(c)));
