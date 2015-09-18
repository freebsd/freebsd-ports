--- src/Csocket.cpp.orig	2015-04-16 15:00:34 UTC
+++ src/Csocket.cpp
@@ -47,6 +47,7 @@
 #include <stdio.h>
 #include <openssl/conf.h>
 #include <openssl/engine.h>
+#include <openssl/comp.h>
 #endif /* HAVE_LIBSSL */
 
 #ifdef HAVE_ICU
@@ -55,6 +55,7 @@ const SSL_METHOD *sycSSLv2_server_method(void) {
 }
 #endif
 
+#ifdef HAVE_SSLv3_client_method
 const SSL_METHOD *sycSSLv3_client_method(void) {
    const SSL_METHOD *result;
    Debug("SSLv3_client_method()");
@@ -62,7 +63,9 @@ const SSL_METHOD *sycSSLv3_client_method(void) {
    Debug1("SSLv3_client_method() -> %p", result);
    return result;
 }
+#endif
 
+#ifdef HAVE_SSLv3_server_method
 const SSL_METHOD *sycSSLv3_server_method(void) {
    const SSL_METHOD *result;
    Debug("SSLv3_server_method()");
@@ -70,6 +73,7 @@ const SSL_METHOD *sycSSLv3_server_method(void) {
    Debug1("SSLv3_server_method() -> %p", result);
    return result;
 }
+#endif
 
 const SSL_METHOD *sycSSLv23_client_method(void) {
    const SSL_METHOD *result;
