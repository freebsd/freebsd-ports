--- src/idevice.c.orig	2015-01-28 01:10:32 UTC
+++ src/idevice.c
@@ -678,7 +678,7 @@ LIBIMOBILEDEVICE_API idevice_error_t ide
 	}
 	BIO_set_fd(ssl_bio, (int)(long)connection->data, BIO_NOCLOSE);
 
-	SSL_CTX *ssl_ctx = SSL_CTX_new(SSLv3_method());
+	SSL_CTX *ssl_ctx = SSL_CTX_new(SSLv23_method());
 	if (ssl_ctx == NULL) {
 		debug_info("ERROR: Could not create SSL context.");
 		BIO_free(ssl_bio);
