--- vio/viosslfactories.c
+++ vio/viosslfactories.c
@@ -123,21 +123,19 @@ static DH *get_dh2048(void)
   DH *dh;
   if ((dh=DH_new()))
   {
-    BIGNUM *p= BN_bin2bn(dh2048_p, sizeof(dh2048_p), NULL);
-    BIGNUM *g= BN_bin2bn(dh2048_g, sizeof(dh2048_g), NULL);
-    if (!p || !g
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
-        || !DH_set0_pqg(dh, p, NULL, g)
-#endif /* OPENSSL_VERSION_NUMBER >= 0x10100000L */
-    ) {
-      /* DH_free() will free 'p' and 'g' at once. */
+    BIGNUM *p = BN_bin2bn(dh2048_p,sizeof(dh2048_p), NULL);
+    BIGNUM *g = BN_bin2bn(dh2048_g,sizeof(dh2048_g), NULL);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+    dh->p=p;
+    dh->g=g;
+    if (! dh->p || ! dh->g)
+#else
+    if (!DH_set0_pqg(dh, p, NULL, g))
+#endif
+    {
       DH_free(dh);
-      return NULL;
+      dh = NULL;
     }
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
-    dh->p= p;
-    dh->g= g;
-#endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   }
   return(dh);
 }
@@ -503,7 +501,7 @@ new_VioSSLFd(const char *key_file, const char *cert_fi
   struct st_VioSSLFd *ssl_fd;
   /* MySQL 5.7 supports TLS up to v1.2, explicitly disable TLSv1.3. */
   long ssl_ctx_options= SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
                         | SSL_OP_NO_TLSv1_3
 #endif /* HAVE_TLSv13 */
                         ;
@@ -536,7 +534,7 @@ new_VioSSLFd(const char *key_file, const char *cert_fi
                     SSL_OP_NO_TLSv1 |
                     SSL_OP_NO_TLSv1_1
                     | SSL_OP_NO_TLSv1_2
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
                     | SSL_OP_NO_TLSv1_3
 #endif /* HAVE_TLSv13 */
                     | SSL_OP_NO_TICKET
@@ -559,7 +557,7 @@ new_VioSSLFd(const char *key_file, const char *cert_fi
 
   SSL_CTX_set_options(ssl_fd->ssl_context, ssl_ctx_options);
 
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
   /*
     MySQL 5.7 doesn't support TLSv1.3 - set empty TLSv1.3 ciphersuites.
   */
