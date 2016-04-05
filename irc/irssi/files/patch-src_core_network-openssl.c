--- src/core/network-openssl.c.orig	2016-03-22 23:08:35 UTC
+++ src/core/network-openssl.c
@@ -486,6 +486,7 @@ static GIOChannel *irssi_ssl_get_iochann
 		if (SSL_CTX_set_cipher_list(ctx, ciphers) != 1)
 			g_warning("No valid SSL cipher suite could be selected");
 	}
+	SSL_CTX_set_options(ctx, SSL_OP_ALL | SSL_OP_NO_SSLv2);
 
 	if (mycert && *mycert) {
 		char *scert = NULL, *spkey = NULL;
