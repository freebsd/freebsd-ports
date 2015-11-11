--- testcode/petal.c.orig	2015-11-11 11:12:49 UTC
+++ testcode/petal.c
@@ -234,8 +234,12 @@ setup_ctx(char* key, char* cert)
 {
 	SSL_CTX* ctx = SSL_CTX_new(SSLv23_server_method());
 	if(!ctx) print_exit("out of memory");
+#ifndef OPENSSL_NO_SSL2
 	(void)SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2);
+#endif
+#ifndef OPENSSL_NO_SSL3
 	(void)SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv3);
+#endif
 	if(!SSL_CTX_use_certificate_chain_file(ctx, cert))
 		print_exit("cannot read cert");
 	if(!SSL_CTX_use_PrivateKey_file(ctx, key, SSL_FILETYPE_PEM))
