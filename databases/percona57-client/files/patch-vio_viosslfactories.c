--- vio/viosslfactories.c.orig	2019-05-16 05:06:00 UTC
+++ vio/viosslfactories.c
@@ -123,7 +123,7 @@ static DH *get_dh2048(void)
   {
     BIGNUM* p= BN_bin2bn(dh2048_p,sizeof(dh2048_p),NULL);
     BIGNUM* g= BN_bin2bn(dh2048_g,sizeof(dh2048_g),NULL);
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     dh->p= p;
     dh->g= g;
     if (! dh->p || ! dh->g)
