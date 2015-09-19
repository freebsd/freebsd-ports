--- src/lib/emile/emile_cipher_openssl.c.orig	2015-07-08 20:33:28.000000000 +0200
+++ src/lib/emile/emile_cipher_openssl.c	2015-09-19 20:09:11.476609538 +0200
@@ -295,7 +295,7 @@ emile_cipher_server_listen(Emile_Cipher_
                              options | SSL_OP_NO_SSLv2 | SSL_OP_SINGLE_DH_USE);
          break;
       case EMILE_SSLv3:
-         r->ssl_ctx = SSL_CTX_new(SSLv3_server_method());
+         r->ssl_ctx = SSL_CTX_new(SSLv23_server_method());
          break;
       case EMILE_TLSv1:
          r->ssl_ctx = SSL_CTX_new(TLSv1_server_method());
@@ -744,7 +744,7 @@ emile_cipher_server_connect(Emile_Cipher
                              options | SSL_OP_NO_SSLv2 | SSL_OP_SINGLE_DH_USE);
          break;
       case EMILE_SSLv3:
-         r->ssl_ctx = SSL_CTX_new(SSLv3_client_method());
+         r->ssl_ctx = SSL_CTX_new(SSLv23_client_method());
          break;
       case EMILE_TLSv1:
          r->ssl_ctx = SSL_CTX_new(TLSv1_client_method());
