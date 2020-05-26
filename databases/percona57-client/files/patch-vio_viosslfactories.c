--- vio/viosslfactories.c.orig	2020-05-13 20:59:55 UTC
+++ vio/viosslfactories.c
@@ -126,7 +126,7 @@ static DH *get_dh2048(void)
   {
     BIGNUM* p= BN_bin2bn(dh2048_p,sizeof(dh2048_p),NULL);
     BIGNUM* g= BN_bin2bn(dh2048_g,sizeof(dh2048_g),NULL);
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     dh->p= p;
     dh->g= g;
     if (! dh->p || ! dh->g)
@@ -500,7 +500,7 @@ new_VioSSLFd(const char *key_file, const char *cert_fi
   struct st_VioSSLFd *ssl_fd;
   /* MySQL 5.7 supports TLS up to v1.2, explicitly disable TLSv1.3. */
   long ssl_ctx_options= SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
                         | SSL_OP_NO_TLSv1_3
 #endif /* HAVE_TLSv13 */
                         ;
@@ -536,7 +536,7 @@ new_VioSSLFd(const char *key_file, const char *cert_fi
                     SSL_OP_NO_TLSv1 |
                     SSL_OP_NO_TLSv1_1
                     | SSL_OP_NO_TLSv1_2
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
                     | SSL_OP_NO_TLSv1_3
 #endif /* HAVE_TLSv13 */
                     | SSL_OP_NO_TICKET
@@ -557,6 +557,7 @@ new_VioSSLFd(const char *key_file, const char *cert_fi
     DBUG_RETURN(0);
   }
 
+#ifndef LIBRESSL_VERSION_NUMBER
   SSL_CTX_set_options(ssl_fd->ssl_context, ssl_ctx_options);
 
 #ifdef HAVE_TLSv13
@@ -573,6 +574,7 @@ new_VioSSLFd(const char *key_file, const char *cert_fi
     DBUG_RETURN(0);
   }
 #endif /* HAVE_TLSv13 */
+#endif /* LIBRESSL_VERSION_NUMBER */
 
   /*
     We explicitly prohibit weak ciphers.
