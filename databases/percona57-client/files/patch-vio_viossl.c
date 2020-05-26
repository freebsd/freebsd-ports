--- vio/viossl.c.orig	2020-05-13 20:59:55 UTC
+++ vio/viossl.c
@@ -396,7 +396,7 @@ static int ssl_do(struct st_VioSSLFd *ptr, Vio *vio,
 #if !defined(DBUG_OFF)
   {
     STACK_OF(SSL_COMP) *ssl_comp_methods = NULL;
-    ssl_comp_methods = SSL_COMP_get_compression_methods();
+    ssl_comp_methods = (STACK_OF(SSL_COMP) *)SSL_COMP_get_compression_methods();
     n= sk_SSL_COMP_num(ssl_comp_methods);
     DBUG_PRINT("info", ("Available compression methods:\n"));
     if (n == 0)
@@ -405,7 +405,7 @@ static int ssl_do(struct st_VioSSLFd *ptr, Vio *vio,
       for (j = 0; j < n; j++)
       {
         SSL_COMP *c = sk_SSL_COMP_value(ssl_comp_methods, j);
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
         DBUG_PRINT("info", ("  %d: %s\n", c->id, c->name));
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
         DBUG_PRINT("info", ("  %d: %s\n", SSL_COMP_get_id(c), SSL_COMP_get0_name(c)));
