--- src/core/network-openssl.c.orig	2018-02-14 23:53:44 UTC
+++ src/core/network-openssl.c
@@ -47,7 +47,8 @@
 
 /* OpenSSL 1.1.0 also introduced some useful additions to the api */
 #if (OPENSSL_VERSION_NUMBER >= 0x10002000L)
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined (LIBRESSL_VERSION_NUMBER)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || \ 
+    (defined (LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x2070000fL)
 static int X509_STORE_up_ref(X509_STORE *vfy)
 {
     int n;
@@ -476,6 +477,7 @@ static GIOChannel *irssi_ssl_get_iochann
 		if (SSL_CTX_set_cipher_list(ctx, ciphers) != 1)
 			g_warning("No valid SSL cipher suite could be selected");
 	}
+	SSL_CTX_set_options(ctx, SSL_OP_ALL | SSL_OP_NO_SSLv2);
 
 	if (mycert && *mycert) {
 		char *scert = NULL, *spkey = NULL;
