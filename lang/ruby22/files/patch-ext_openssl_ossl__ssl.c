--- ext/openssl/ossl_ssl.c.orig	2014-12-12 22:58:34.000000000 +0100
+++ ext/openssl/ossl_ssl.c	2015-09-18 10:48:59.377881194 +0200
@@ -138,9 +138,12 @@ static const struct {
     OSSL_SSL_METHOD_ENTRY(SSLv2_server),
     OSSL_SSL_METHOD_ENTRY(SSLv2_client),
 #endif
+#if defined(HAVE_SSLV3_METHOD) && defined(HAVE_SSLV3_SERVER_METHOD) && \
+        defined(HAVE_SSLV3_CLIENT_METHOD)
     OSSL_SSL_METHOD_ENTRY(SSLv3),
     OSSL_SSL_METHOD_ENTRY(SSLv3_server),
     OSSL_SSL_METHOD_ENTRY(SSLv3_client),
+#endif
     OSSL_SSL_METHOD_ENTRY(SSLv23),
     OSSL_SSL_METHOD_ENTRY(SSLv23_server),
     OSSL_SSL_METHOD_ENTRY(SSLv23_client),
