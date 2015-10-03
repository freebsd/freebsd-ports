--- ckcssl.h.orig	1999-09-21 04:08:20.000000000 +0200
+++ ckcssl.h	2015-10-03 14:35:05.123628000 +0200
@@ -71,13 +71,15 @@ _PROTOTYP(int ssl_client_verify_callback
 #define SSL_CTX_free                     ck_SSL_CTX_free
 #define SSL_CTX_set_default_passwd_cb    ck_SSL_CTX_set_default_passwd_cb
 #define SSLv23_method                    ck_SSLv23_method
+#ifndef OPENSSL_NO_SSL3
 #define SSLv3_method                     ck_SSLv3_method
+#define SSLv3_client_method              ck_SSLv3_client_method
+#define SSLv3_server_method              ck_SSLv3_server_method
+#endif
 #define TLSv1_method                     ck_TLSv1_method
 #define SSLv23_client_method             ck_SSLv23_client_method
-#define SSLv3_client_method              ck_SSLv3_client_method
 #define TLSv1_client_method              ck_TLSv1_client_method
 #define SSLv23_server_method             ck_SSLv23_server_method
-#define SSLv3_server_method              ck_SSLv3_server_method
 #define TLSv1_server_method              ck_TLSv1_server_method
 #define SSL_library_init                 ck_SSL_library_init
 #define SSL_state_string                 ck_SSL_state_string
