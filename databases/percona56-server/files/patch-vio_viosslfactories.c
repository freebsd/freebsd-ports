--- vio/viosslfactories.c.orig	2020-07-21 12:31:43.000000000 +0200
+++ vio/viosslfactories.c	2020-09-17 22:38:47.837385000 +0200
@@ -128,7 +128,7 @@
     BIGNUM *p= BN_bin2bn(dh2048_p, sizeof(dh2048_p), NULL);
     BIGNUM *g= BN_bin2bn(dh2048_g, sizeof(dh2048_g), NULL);
     if (!p || !g
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L || defined( LIBRESSL_VERSION_NUMBER )
         || !DH_set0_pqg(dh, p, NULL, g)
 #endif /* OPENSSL_VERSION_NUMBER >= 0x10100000L */
     ) {
@@ -136,7 +136,7 @@
       DH_free(dh);
       return NULL;
     }
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined( LIBRESSL_VERSION_NUMBER )
     dh->p= p;
     dh->g= g;
 #endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
