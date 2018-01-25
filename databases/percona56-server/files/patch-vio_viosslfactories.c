--- vio/viosslfactories.c.orig	2018-01-17 11:42:33.764076000 +0000
+++ vio/viosslfactories.c	2018-01-17 11:43:21.072238000 +0000
@@ -125,7 +125,7 @@
   {
     BIGNUM* p= BN_bin2bn(dh2048_p,sizeof(dh2048_p),NULL);
     BIGNUM* g= BN_bin2bn(dh2048_g,sizeof(dh2048_g),NULL);
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined( LIBRESSL_VERSION_NUMBER )
     dh->p= p;
     dh->g= g;
     if (! dh->p || ! dh->g)
