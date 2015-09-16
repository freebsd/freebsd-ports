$OpenBSD: patch-ext_openssl_ossl_ssl_c,v 1.1 2015/08/27 15:55:04 kili Exp $
--- ext/openssl/ossl_ssl.c.orig	Mon Jan 27 08:47:11 2014
+++ ext/openssl/ossl_ssl.c	Thu Aug 27 17:22:10 2015
@@ -134,9 +134,12 @@ struct {
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
