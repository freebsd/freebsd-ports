Obtained from:	https://github.com/jedisct1/pure-ftpd/commit/4a495c61ce22c893aed5ee57f6ce0b43c3be59ad

--- src/tls.c.orig	2017-08-18 23:47:43 UTC
+++ src/tls.c
@@ -228,7 +228,16 @@ static void ssl_info_cb(const SSL *cnx, 
     if ((where & SSL_CB_HANDSHAKE_START) != 0) {
         if ((cnx == tls_cnx && tls_cnx_handshook != 0) ||
             (cnx == tls_data_cnx && tls_data_cnx_handshook != 0)) {
-            die(400, LOG_ERR, "TLS renegociation");
+            const SSL_CIPHER *cipher;
+            const char *cipher_version;
+            if ((cipher = SSL_get_current_cipher(cnx)) == NULL ||
+                (cipher_version = SSL_CIPHER_get_version(cipher)) == NULL) {
+                die(400, LOG_ERR, "No cipher");
+            }
+            if (strcmp(cipher_version, "TLSv1.3") != 0) {
+                die(400, LOG_ERR, "TLS renegociation");
+                return;
+            }
         }
         return;
     }
@@ -264,10 +273,10 @@ int tls_init_library(void)
     OpenSSL_add_all_algorithms();
 # else
     OPENSSL_init_ssl(OPENSSL_INIT_LOAD_SSL_STRINGS |
-		     OPENSSL_INIT_LOAD_CRYPTO_STRINGS, NULL);
+                     OPENSSL_INIT_LOAD_CRYPTO_STRINGS, NULL);
     OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_CIPHERS |
-			OPENSSL_INIT_ADD_ALL_DIGESTS |
-			OPENSSL_INIT_LOAD_CONFIG, NULL);
+                        OPENSSL_INIT_ADD_ALL_DIGESTS |
+                        OPENSSL_INIT_LOAD_CONFIG, NULL);
 # endif
     while (RAND_status() == 0) {
         rnd = zrand();
