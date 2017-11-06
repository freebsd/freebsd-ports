--- src/libmongoc/src/mongoc/mongoc-stream-tls-openssl.c.orig	2017-01-17 18:35:13 UTC
+++ src/libmongoc/src/mongoc/mongoc-stream-tls-openssl.c
@@ -638,7 +638,7 @@ mongoc_stream_tls_openssl_new (mongoc_st
       RETURN(NULL);
    }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10002000L
+#if OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(LIBRESSL_VERSION_NUMBER)
    if (!opt->allow_invalid_hostname) {
       struct in_addr addr;
       X509_VERIFY_PARAM *param = X509_VERIFY_PARAM_new();
