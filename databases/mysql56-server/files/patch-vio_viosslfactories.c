--- vio/viosslfactories.c.orig	2019-11-26 16:53:45 UTC
+++ vio/viosslfactories.c
@@ -91,7 +91,7 @@ static DH *get_dh2048(void)
       DH_free(dh);
       return NULL;
     }
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     dh->p= p;
     dh->g= g;
 #endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
@@ -226,7 +226,7 @@ new_VioSSLFd(const char *key_file, const char *cert_fi
   struct st_VioSSLFd *ssl_fd;
   /* MySQL 5.6 supports TLS up to v1.2, explicitly disable TLSv1.3. */
   long ssl_ctx_options= SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3 |
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
                         SSL_OP_NO_TLSv1_3 |
 #endif /* HAVE_TLSv13 */
                         SSL_OP_NO_TICKET;
@@ -250,7 +250,7 @@ new_VioSSLFd(const char *key_file, const char *cert_fi
     DBUG_RETURN(0);
 
   if (!(ssl_fd->ssl_context= SSL_CTX_new(is_client ?
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
                                          SSLv23_client_method() :
                                          SSLv23_server_method()
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
@@ -268,7 +268,7 @@ new_VioSSLFd(const char *key_file, const char *cert_fi
 
   SSL_CTX_set_options(ssl_fd->ssl_context, ssl_ctx_options);
 
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
   /*
     MySQL 5.6 doesn't support TLSv1.3 - set empty TLSv1.3 ciphersuites.
   */
