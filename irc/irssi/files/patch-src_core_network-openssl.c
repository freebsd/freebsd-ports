--- src/core/network-openssl.c.orig	2017-03-10 16:31:03 UTC
+++ src/core/network-openssl.c
@@ -434,6 +434,7 @@ static GIOChannel *irssi_ssl_get_iochann
 		if (SSL_CTX_set_cipher_list(ctx, ciphers) != 1)
 			g_warning("No valid SSL cipher suite could be selected");
 	}
+	SSL_CTX_set_options(ctx, SSL_OP_ALL | SSL_OP_NO_SSLv2);
 
 	if (mycert && *mycert) {
 		char *scert = NULL, *spkey = NULL;
