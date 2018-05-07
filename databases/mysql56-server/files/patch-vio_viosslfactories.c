--- vio/viosslfactories.c.orig	2017-12-09 07:33:37 UTC
+++ vio/viosslfactories.c
@@ -68,13 +68,20 @@ static DH *get_dh2048(void)
   DH *dh;
   if ((dh=DH_new()))
   {
-    dh->p=BN_bin2bn(dh2048_p,sizeof(dh2048_p),NULL);
-    dh->g=BN_bin2bn(dh2048_g,sizeof(dh2048_g),NULL);
-    if (! dh->p || ! dh->g)
-    {
+    BIGNUM *p= BN_bin2bn(dh2048_p,sizeof(dh2048_p),NULL);
+    BIGNUM *g= BN_bin2bn(dh2048_g,sizeof(dh2048_g),NULL);
+    if (!p || !g
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+        || !DH_set0_pqg(dh, p, NULL, g)
+#endif /* OPENSSL_VERSION_NUMBER >= 0x10100000L */
+    ) {
       DH_free(dh);
       dh=0;
     }
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+    dh->p= p;
+    dh->g= g;
+#endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   }
   return(dh);
 }
