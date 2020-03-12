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
@@ -250,7 +250,7 @@ new_VioSSLFd(const char *key_file, const char *cert_fi
     DBUG_RETURN(0);
 
   if (!(ssl_fd->ssl_context= SSL_CTX_new(is_client ?
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
                                          SSLv23_client_method() :
                                          SSLv23_server_method()
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
