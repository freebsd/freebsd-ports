--- bbftpd_crypt.c.orig	2004-06-30 17:38:50 UTC
+++ bbftpd_crypt.c
@@ -84,8 +84,13 @@ void sendcrypt() 
     /*
     ** Now extract the public key in order to send it
     */
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     lenkey  = BN_bn2mpi(myrsa->n,pubkey) ;
     lenexpo = BN_bn2mpi(myrsa->e,pubexponent) ;
+#else
+    lenkey  = BN_bn2mpi(RSA_get0_n(myrsa),pubkey) ;
+    lenexpo = BN_bn2mpi(RSA_get0_e(myrsa),pubexponent) ;
+#endif
     mess = (struct message *) buf ;
     mess->code = MSG_CRYPT ;
 #ifndef WORDS_BIGENDIAN
