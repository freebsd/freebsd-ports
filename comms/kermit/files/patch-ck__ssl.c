--- ck_ssl.c.orig	2017-04-26 15:56:23 UTC
+++ ck_ssl.c
@@ -303,7 +303,7 @@ X509_STORE_CTX *ctx;
                 break;
             default:
                 printf("Error %d while verifying certificate.\r\n",
-                       ctx->error);
+                       error);
                 break;
             }
         }
@@ -935,13 +935,32 @@ static DH *
 get_dh512()
 {
     DH *dh=NULL;
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    BIGNUM *p, *g;
+#endif
 
     if ((dh=DH_new()) == NULL)
         return(NULL);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    p=BN_bin2bn(dh512_p,sizeof(dh512_p),NULL);
+    g=BN_bin2bn(dh512_g,sizeof(dh512_g),NULL);
+    if (p == NULL || g == NULL) {
+        BN_free(g);
+        BN_free(p);
+        DH_free(dh);
+        return(NULL);
+    } else
+        DH_set0_pqg(dh, p, NULL, g);
+#else
     dh->p=BN_bin2bn(dh512_p,sizeof(dh512_p),NULL);
     dh->g=BN_bin2bn(dh512_g,sizeof(dh512_g),NULL);
-    if ((dh->p == NULL) || (dh->g == NULL))
+    if ((dh->p == NULL) || (dh->g == NULL)) {
+        BN_free(dh->g);
+        BN_free(dh->p);
+        DH_free(dh);
         return(NULL);
+    }
+#endif
     return(dh);
 }
 
@@ -949,13 +968,32 @@ static DH *
 get_dh768()
 {
     DH *dh=NULL;
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    BIGNUM *p, *g;
+#endif
 
     if ((dh=DH_new()) == NULL)
         return(NULL);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    p=BN_bin2bn(dh768_p,sizeof(dh768_p),NULL);
+    g=BN_bin2bn(dh768_g,sizeof(dh768_g),NULL);
+    if (p == NULL || g == NULL) {
+        BN_free(g);
+        BN_free(p);
+        DH_free(dh);
+        return(NULL);
+    } else
+        DH_set0_pqg(dh, p, NULL, g);
+#else
     dh->p=BN_bin2bn(dh768_p,sizeof(dh768_p),NULL);
     dh->g=BN_bin2bn(dh768_g,sizeof(dh768_g),NULL);
-    if ((dh->p == NULL) || (dh->g == NULL))
+    if ((dh->p == NULL) || (dh->g == NULL)) {
+        BN_free(dh->g);
+        BN_free(dh->p);
+        DH_free(dh);
         return(NULL);
+    }
+#endif
     return(dh);
 }
 
@@ -963,13 +1001,32 @@ static DH *
 get_dh1024()
 {
     DH *dh=NULL;
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    BIGNUM *p, *g;
+#endif
 
     if ((dh=DH_new()) == NULL)
         return(NULL);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    p=BN_bin2bn(dh1024_p,sizeof(dh1024_p),NULL);
+    g=BN_bin2bn(dh1024_g,sizeof(dh1024_g),NULL);
+    if (p == NULL || g == NULL) {
+        BN_free(g);
+        BN_free(p);
+        DH_free(dh);
+        return(NULL);
+    } else
+        DH_set0_pqg(dh, p, NULL, g);
+#else
     dh->p=BN_bin2bn(dh1024_p,sizeof(dh1024_p),NULL);
     dh->g=BN_bin2bn(dh1024_g,sizeof(dh1024_g),NULL);
-    if ((dh->p == NULL) || (dh->g == NULL))
+    if ((dh->p == NULL) || (dh->g == NULL)) {
+        BN_free(dh->g);
+        BN_free(dh->p);
+        DH_free(dh);
         return(NULL);
+    }
+#endif
     return(dh);
 }
 
@@ -977,13 +1034,32 @@ static DH *
 get_dh1536()
 {
     DH *dh=NULL;
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    BIGNUM *p, *g;
+#endif
 
     if ((dh=DH_new()) == NULL)
         return(NULL);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    p=BN_bin2bn(dh1536_p,sizeof(dh1536_p),NULL);
+    g=BN_bin2bn(dh1536_g,sizeof(dh1536_g),NULL);
+    if (p == NULL || g == NULL) {
+        BN_free(g);
+        BN_free(p);
+        DH_free(dh);
+        return(NULL);
+    } else
+        DH_set0_pqg(dh, p, NULL, g);
+#else
     dh->p=BN_bin2bn(dh1536_p,sizeof(dh1536_p),NULL);
     dh->g=BN_bin2bn(dh1536_g,sizeof(dh1536_g),NULL);
-    if ((dh->p == NULL) || (dh->g == NULL))
+    if ((dh->p == NULL) || (dh->g == NULL)) {
+        BN_free(dh->g);
+        BN_free(dh->p);
+        DH_free(dh);
         return(NULL);
+    }
+#endif
     return(dh);
 }
 
@@ -991,13 +1067,32 @@ static DH *
 get_dh2048()
 {
     DH *dh=NULL;
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    BIGNUM *p, *g;
+#endif
 
     if ((dh=DH_new()) == NULL)
         return(NULL);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    p=BN_bin2bn(dh2048_p,sizeof(dh2048_p),NULL);
+    g=BN_bin2bn(dh2048_g,sizeof(dh2048_g),NULL);
+    if (p == NULL || g == NULL) {
+        BN_free(g);
+        BN_free(p);
+        DH_free(dh);
+        return(NULL);
+    } else
+        DH_set0_pqg(dh, p, NULL, g);
+#else
     dh->p=BN_bin2bn(dh2048_p,sizeof(dh2048_p),NULL);
     dh->g=BN_bin2bn(dh2048_g,sizeof(dh2048_g),NULL);
-    if ((dh->p == NULL) || (dh->g == NULL))
+    if ((dh->p == NULL) || (dh->g == NULL)) {
+        BN_free(dh->g);
+        BN_free(dh->p);
+        DH_free(dh);
         return(NULL);
+    }
+#endif
     return(dh);
 }
 #endif /* NO_DH */
@@ -1057,13 +1152,13 @@ ssl_display_comp(SSL * ssl)
         return;
 
 #ifndef OPENSSL_NO_COMP                  /* ifdefs Bernard Spil 12/2015 */
-    if (ssl->expand == NULL || ssl->expand->meth == NULL)
+    if (SSL_get_current_expansion(ssl) == NULL)
 #endif /* OPENSSL_NO_COMP */
         printf("Compression: None\r\n");
 
 #ifndef OPENSSL_NO_COMP                  /* ifdefs Bernard Spil 12/2015 */
     else {
-        printf("Compression: %s\r\n",ssl->expand->meth->name);
+        printf("Compression: %s\r\n", SSL_COMP_get_name(SSL_get_current_expansion(ssl)));
     }
 #endif /* OPENSSL_NO_COMP */
 }
@@ -1489,13 +1584,23 @@ the build.\r\n\r\n");
 
 #ifdef ZLIB
     cm = COMP_zlib();
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    if (cm != NULL && COMP_get_type(cm) != NID_undef) {
+#else
     if (cm != NULL && cm->type != NID_undef) {
+#endif
         SSL_COMP_add_compression_method(0xe0, cm); /* EAY's ZLIB ID */
     }
 #endif /* ZLIB */
+#ifdef NID_rle_compression
     cm = COMP_rle();
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    if (cm != NULL && COMP_get_type(cm) != NID_undef)
+#else
     if (cm != NULL && cm->type != NID_undef)
+#endif
         SSL_COMP_add_compression_method(0xe1, cm); /* EAY's RLE ID */
+#endif /* NID_rle_compression */
 
     /* Ensure the Random number generator has enough entropy */
     if ( !RAND_status() ) {
@@ -2623,7 +2728,11 @@ ssl_anonymous_cipher(ssl) SSL * ssl;
 int
 ssl_verify_crl(int ok, X509_STORE_CTX *ctx)
 {
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    X509_OBJECT *obj;
+#else
     X509_OBJECT obj;
+#endif
     X509_NAME *subject = NULL;
     X509_NAME *issuer = NULL;
     X509 *xs = NULL;
@@ -2643,6 +2752,12 @@ ssl_verify_crl(int ok, X509_STORE_CTX *ctx)
     if (!crl_store)
         return ok;
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    obj = X509_OBJECT_new();
+    if (!obj)
+        return(ok);
+#endif
+
     store_ctx = X509_STORE_CTX_new();
     if ( !store_ctx )
         return(ok);
@@ -2689,11 +2804,19 @@ ssl_verify_crl(int ok, X509_STORE_CTX *ctx)
      * Try to retrieve a CRL corresponding to the _subject_ of
      * the current certificate in order to verify it's integrity.
      */
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
     memset((char *)&obj, 0, sizeof(obj));
+#endif
     X509_STORE_CTX_init(store_ctx, crl_store, NULL, NULL);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    rc = X509_STORE_get_by_subject(store_ctx, X509_LU_CRL, subject, obj);
+    X509_STORE_CTX_cleanup(store_ctx);
+    crl = X509_OBJECT_get0_X509_CRL(obj);
+#else
     rc = X509_STORE_get_by_subject(store_ctx, X509_LU_CRL, subject, &obj);
     X509_STORE_CTX_cleanup(store_ctx);
     crl = obj.data.crl;
+#endif
     if (rc > 0 && crl != NULL) {
         /*
          * Verify the signature on this CRL
@@ -2701,7 +2824,11 @@ ssl_verify_crl(int ok, X509_STORE_CTX *ctx)
         if (X509_CRL_verify(crl, X509_get_pubkey(xs)) <= 0) {
             fprintf(stderr, "Invalid signature on CRL!\n");
             X509_STORE_CTX_set_error(ctx, X509_V_ERR_CRL_SIGNATURE_FAILURE);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+            X509_OBJECT_free(obj);
+#else
             X509_OBJECT_free_contents(&obj);
+#endif
             X509_STORE_CTX_free(store_ctx);
             return 0;
         }
@@ -2714,7 +2841,11 @@ ssl_verify_crl(int ok, X509_STORE_CTX *ctx)
             fprintf(stderr, "Found CRL has invalid nextUpdate field.\n");
             X509_STORE_CTX_set_error(ctx,
                                     X509_V_ERR_ERROR_IN_CRL_NEXT_UPDATE_FIELD);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+            X509_OBJECT_free(obj);
+#else
             X509_OBJECT_free_contents(&obj);
+#endif
             X509_STORE_CTX_free(store_ctx);
             return 0;
         }
@@ -2723,22 +2854,38 @@ ssl_verify_crl(int ok, X509_STORE_CTX *ctx)
 "Found CRL is expired - revoking all certificates until you get updated CRL.\n"
                     );
             X509_STORE_CTX_set_error(ctx, X509_V_ERR_CRL_HAS_EXPIRED);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+            X509_OBJECT_free(obj);
+#else
             X509_OBJECT_free_contents(&obj);
+#endif
             X509_STORE_CTX_free(store_ctx);
             return 0;
         }
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+        X509_OBJECT_free(obj);
+#else
         X509_OBJECT_free_contents(&obj);
+#endif
     }
 
     /*
      * Try to retrieve a CRL corresponding to the _issuer_ of
      * the current certificate in order to check for revocation.
      */
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
     memset((char *)&obj, 0, sizeof(obj));
+#endif
     X509_STORE_CTX_init(store_ctx, crl_store, NULL, NULL);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    rc = X509_STORE_get_by_subject(store_ctx, X509_LU_CRL, issuer, obj);
+    X509_STORE_CTX_free(store_ctx);		/* calls X509_STORE_CTX_cleanup() */
+    crl = X509_OBJECT_get0_X509_CRL(obj);
+#else
     rc = X509_STORE_get_by_subject(store_ctx, X509_LU_CRL, issuer, &obj);
     X509_STORE_CTX_free(store_ctx);		/* calls X509_STORE_CTX_cleanup() */
     crl = obj.data.crl;
+#endif
     if (rc > 0 && crl != NULL) {
         /*
          * Check if the current certificate is revoked by this CRL
@@ -2746,19 +2893,34 @@ ssl_verify_crl(int ok, X509_STORE_CTX *ctx)
         n = sk_X509_REVOKED_num(X509_CRL_get_REVOKED(crl));
         for (i = 0; i < n; i++) {
             revoked = sk_X509_REVOKED_value(X509_CRL_get_REVOKED(crl), i);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+            if (ASN1_INTEGER_cmp(X509_REVOKED_get0_serialNumber(revoked),
+                                 X509_get_serialNumber(xs)) == 0) {
+
+                serial = ASN1_INTEGER_get(X509_REVOKED_get0_serialNumber(revoked));
+#else
             if (ASN1_INTEGER_cmp(revoked->serialNumber,
                                  X509_get_serialNumber(xs)) == 0) {
 
                 serial = ASN1_INTEGER_get(revoked->serialNumber);
+#endif
                 cp = X509_NAME_oneline(issuer, NULL, 0);
                 free(cp);
 
                 X509_STORE_CTX_set_error(ctx, X509_V_ERR_CERT_REVOKED);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+                X509_OBJECT_free(obj);
+#else
                 X509_OBJECT_free_contents(&obj);
+#endif
                 return 0;
             }
         }
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+        X509_OBJECT_free(obj);
+#else
         X509_OBJECT_free_contents(&obj);
+#endif
     }
     return ok;
 }
@@ -4399,7 +4561,14 @@ X509_userok(X509 * peer_cert, const char * userid)
     if (!(fp = fopen(buf, "r")))
         return 0;
     while (!r && (file_cert = PEM_read_X509(fp, NULL, NULL, NULL))) {
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+        ASN1_BIT_STRING *peer_cert_sig, *file_cert_sig;
+        X509_get0_signature(&peer_cert_sig, NULL, peer_cert);
+        X509_get0_signature(&file_cert_sig, NULL, file_cert);
+        if (!ASN1_STRING_cmp(peer_cert_sig, file_cert_sig))
+#else
         if (!ASN1_STRING_cmp(peer_cert->signature, file_cert->signature))
+#endif
             r = 1;
         X509_free(file_cert);
     }
