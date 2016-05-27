--- src/qt/qtbase/src/network/ssl/qsslsocket_openssl_symbols.cpp.orig	2015-01-24 02:19:52 UTC
+++ src/qt/qtbase/src/network/ssl/qsslsocket_openssl_symbols.cpp
@@ -266,7 +266,9 @@ DEFINEFUNC(SSL_SESSION*, SSL_get_session
 #ifndef OPENSSL_NO_SSL2
 DEFINEFUNC(const SSL_METHOD *, SSLv2_client_method, DUMMYARG, DUMMYARG, return 0, return)
 #endif
+#ifndef OPENSSL_NO_SSL3
 DEFINEFUNC(const SSL_METHOD *, SSLv3_client_method, DUMMYARG, DUMMYARG, return 0, return)
+#endif
 DEFINEFUNC(const SSL_METHOD *, SSLv23_client_method, DUMMYARG, DUMMYARG, return 0, return)
 DEFINEFUNC(const SSL_METHOD *, TLSv1_client_method, DUMMYARG, DUMMYARG, return 0, return)
 #if OPENSSL_VERSION_NUMBER >= 0x10001000L
@@ -276,7 +278,9 @@ DEFINEFUNC(const SSL_METHOD *, TLSv1_2_c
 #ifndef OPENSSL_NO_SSL2
 DEFINEFUNC(const SSL_METHOD *, SSLv2_server_method, DUMMYARG, DUMMYARG, return 0, return)
 #endif
+#ifndef OPENSSL_NO_SSL3
 DEFINEFUNC(const SSL_METHOD *, SSLv3_server_method, DUMMYARG, DUMMYARG, return 0, return)
+#endif
 DEFINEFUNC(const SSL_METHOD *, SSLv23_server_method, DUMMYARG, DUMMYARG, return 0, return)
 DEFINEFUNC(const SSL_METHOD *, TLSv1_server_method, DUMMYARG, DUMMYARG, return 0, return)
 #if OPENSSL_VERSION_NUMBER >= 0x10001000L
