Obtained from:	https://github.com/curl/curl/commit/a3d5b199f96a108f38bd1f6adaf3a7585f721d02

--- lib/vtls/openssl.c.orig
+++ lib/vtls/openssl.c
@@ -225,6 +225,14 @@
   "ALL:!EXPORT:!EXPORT40:!EXPORT56:!aNULL:!LOW:!RC4:@STRENGTH"
 #endif
 
+#ifdef HAVE_OPENSSL_SRP
+/* the function exists */
+#ifdef USE_TLS_SRP
+/* the functionality is not disabled */
+#define USE_OPENSSL_SRP
+#endif
+#endif
+
 struct ssl_backend_data {
   /* these ones requires specific SSL-types */
   SSL_CTX* ctx;
@@ -2471,7 +2479,7 @@ static CURLcode ossl_connect_step1(struct connectdata *conn, int sockindex)
 #endif
 #endif
   const long int ssl_version = SSL_CONN_CONFIG(version);
-#ifdef HAVE_OPENSSL_SRP
+#ifdef USE_OPENSSL_SRP
   const enum CURL_TLSAUTH ssl_authtype = SSL_SET_OPTION(authtype);
 #endif
   char * const ssl_cert = SSL_SET_OPTION(primary.clientcert);
@@ -2516,7 +2524,7 @@ static CURLcode ossl_connect_step1(struct connectdata *conn, int sockindex)
     failf(data, OSSL_PACKAGE " was built without SSLv2 support");
     return CURLE_NOT_BUILT_IN;
 #else
-#ifdef HAVE_OPENSSL_SRP
+#ifdef USE_OPENSSL_SRP
     if(ssl_authtype == CURL_TLSAUTH_SRP)
       return CURLE_SSL_CONNECT_ERROR;
 #endif
@@ -2529,7 +2537,7 @@ static CURLcode ossl_connect_step1(struct connectdata *conn, int sockindex)
     failf(data, OSSL_PACKAGE " was built without SSLv3 support");
     return CURLE_NOT_BUILT_IN;
 #else
-#ifdef HAVE_OPENSSL_SRP
+#ifdef USE_OPENSSL_SRP
     if(ssl_authtype == CURL_TLSAUTH_SRP)
       return CURLE_SSL_CONNECT_ERROR;
 #endif
@@ -2797,7 +2805,7 @@ static CURLcode ossl_connect_step1(struct connectdata *conn, int sockindex)
   }
 #endif
 
-#ifdef HAVE_OPENSSL_SRP
+#ifdef USE_OPENSSL_SRP
   if(ssl_authtype == CURL_TLSAUTH_SRP) {
     char * const ssl_username = SSL_SET_OPTION(username);
 
