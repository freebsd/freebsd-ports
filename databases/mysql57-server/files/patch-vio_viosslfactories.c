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
