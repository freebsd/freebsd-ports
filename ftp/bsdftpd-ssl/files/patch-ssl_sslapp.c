--- ssl/sslapp.c.orig	2005-01-10 23:34:59 UTC
+++ ssl/sslapp.c
@@ -113,10 +113,14 @@ do_ssleay_init(int server)
 
 	    if (SSL_CTX_need_tmp_RSA(ssl_ctx)) {
 		    RSA *rsa;
+		    BIGNUM *e;
 
 		    if (ssl_debug_flag)
 			    ssl_log_msgn(bio_err, "Generating temp (512 bit) RSA key...");
-		    rsa = RSA_generate_key(512, RSA_F4, NULL, NULL);
+
+		    e = BN_new();
+		    BN_set_word(e, RSA_F4);
+		    RSA_generate_key_ex(rsa, 512, e, NULL);
 		    if (ssl_debug_flag)
 			    ssl_log_msgn(bio_err, "Generation of temp (512 bit) RSA key done");
 
@@ -289,12 +293,13 @@ int
 ssl_X509_STORE_lookup(X509_STORE *pStore, int nType,
 			X509_NAME *pName, X509_OBJECT *pObj)
 {
-    X509_STORE_CTX pStoreCtx;
+    X509_STORE_CTX *pStoreCtx;
     int rc;
 
-    X509_STORE_CTX_init(&pStoreCtx, pStore, NULL, NULL);
-    rc = X509_STORE_get_by_subject(&pStoreCtx, nType, pName, pObj);
-    X509_STORE_CTX_cleanup(&pStoreCtx);
+    pStoreCtx = X509_STORE_CTX_new();
+    X509_STORE_CTX_init(pStoreCtx, pStore, NULL, NULL);
+    rc = X509_STORE_get_by_subject(pStoreCtx, nType, pName, pObj);
+    X509_STORE_CTX_free(pStoreCtx);
     return rc;
 }
 
@@ -311,7 +316,7 @@ ssl_X509_STORE_lookup(X509_STORE *pStore, int nType,
 int
 verify_cb_CRL(int ok, X509_STORE_CTX *ctx)
 {
-    X509_OBJECT obj;
+    X509_OBJECT *obj;
     X509_NAME *subject;
     X509_NAME *issuer;
     X509 *xs;
@@ -368,16 +373,16 @@ verify_cb_CRL(int ok, X509_STORE_CTX *ctx)
      * Try to retrieve a CRL corresponding to the _subject_ of
      * the current certificate in order to verify it's integrity.
      */
-    memset((char *)&obj, 0, sizeof(obj));
-    rc = ssl_X509_STORE_lookup(x509st_CRL, X509_LU_CRL, subject, &obj);
-    crl = obj.data.crl;
+    obj = X509_OBJECT_new();
+    rc = ssl_X509_STORE_lookup(x509st_CRL, X509_LU_CRL, subject, obj);
+    crl = X509_OBJECT_get0_X509_CRL(obj);
     if (rc > 0 && crl != NULL) {
         /*
          * Verify the signature on this CRL
          */
         if (X509_CRL_verify(crl, X509_get_pubkey(xs)) <= 0) {
             X509_STORE_CTX_set_error(ctx, X509_V_ERR_CRL_SIGNATURE_FAILURE);
-            X509_OBJECT_free_contents(&obj);
+            X509_OBJECT_free(obj);
             return 0;
         }
 
@@ -387,24 +392,24 @@ verify_cb_CRL(int ok, X509_STORE_CTX *ctx)
         i = X509_cmp_current_time(X509_CRL_get_nextUpdate(crl));
         if (i == 0) {
             X509_STORE_CTX_set_error(ctx, X509_V_ERR_ERROR_IN_CRL_NEXT_UPDATE_FIELD);
-            X509_OBJECT_free_contents(&obj);
+            X509_OBJECT_free(obj);
             return 0;
         }
         if (i < 0) {
             X509_STORE_CTX_set_error(ctx, X509_V_ERR_CRL_HAS_EXPIRED);
-            X509_OBJECT_free_contents(&obj);
+            X509_OBJECT_free(obj);
             return 0;
         }
-        X509_OBJECT_free_contents(&obj);
+        X509_OBJECT_free(obj);
     }
 
     /*
      * Try to retrieve a CRL corresponding to the _issuer_ of
      * the current certificate in order to check for revocation.
      */
-    memset((char *)&obj, 0, sizeof(obj));
-    rc = ssl_X509_STORE_lookup(x509st_CRL, X509_LU_CRL, issuer, &obj);
-    crl = obj.data.crl;
+    obj = X509_OBJECT_new();
+    rc = ssl_X509_STORE_lookup(x509st_CRL, X509_LU_CRL, issuer, obj);
+    crl = X509_OBJECT_get0_X509_CRL(obj);
     if (rc > 0 && crl != NULL) {
         /*
          * Check if the current certificate is revoked by this CRL
@@ -412,13 +417,14 @@ verify_cb_CRL(int ok, X509_STORE_CTX *ctx)
         n = sk_X509_REVOKED_num(X509_CRL_get_REVOKED(crl));
         for (i = 0; i < n; i++) {
             revoked = sk_X509_REVOKED_value(X509_CRL_get_REVOKED(crl), i);
-            if (ASN1_INTEGER_cmp(revoked->serialNumber, X509_get_serialNumber(xs)) == 0) {
+            if (ASN1_INTEGER_cmp(X509_REVOKED_get0_serialNumber(revoked),
+              X509_get_serialNumber(xs)) == 0) {
                 X509_STORE_CTX_set_error(ctx, X509_V_ERR_CERT_REVOKED);
-                X509_OBJECT_free_contents(&obj);
+                X509_OBJECT_free(obj);
                 return 0;
             }
         }
-        X509_OBJECT_free_contents(&obj);
+        X509_OBJECT_free(obj);
     }
     return ok;
 }
