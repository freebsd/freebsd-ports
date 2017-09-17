--- lib/usual/tls/tls.c.orig	2016-02-15 07:18:25 UTC
+++ lib/usual/tls/tls.c
@@ -40,11 +40,13 @@ tls_init(void)
 	if (tls_initialised)
 		return (0);
 
+#ifdef USE_LIBSSL_OLD
 	SSL_load_error_strings();
 	SSL_library_init();
 
 	if (BIO_sock_init() != 1)
 		return (-1);
+#endif
 
 	if ((tls_config_default = tls_config_new()) == NULL)
 		return (-1);
@@ -63,12 +65,16 @@ tls_deinit(void)
 		tls_config_free(tls_config_default);
 		tls_config_default = NULL;
 
+#ifdef USE_LIBSSL_OLD
 		EVP_cleanup();
 		CRYPTO_cleanup_all_ex_data();
 		BIO_sock_cleanup();
 		ERR_clear_error();
 		ERR_remove_thread_state(NULL);
 		ERR_free_strings();
+#else
+		OPENSSL_cleanup();
+#endif
 
 		tls_initialised = 0;
 	}
