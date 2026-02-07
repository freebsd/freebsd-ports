--- bbftpd_crypt.c.orig	2004-06-30 17:38:50 UTC
+++ bbftpd_crypt.c
@@ -73,19 +73,25 @@ void sendcrypt() 
     unsigned char    pubexponent[NBITSINKEY] ;
     int        lenkey ;
     int        lenexpo ;
+    BIGNUM *e = BN_new();
     
     /*
     ** Ask for the private and public Key
     */
-    if ( (myrsa = RSA_generate_key(NBITSINKEY,3,NULL,NULL)) == NULL) {
+    if (e == NULL || (BN_set_word(e,3) && RSA_generate_key_ex(myrsa,NBITSINKEY,e,NULL)) == 0) {
         syslog(BBFTPD_ERR,"%s",ERR_error_string(ERR_get_error(),NULL) ) ;
         exit(1) ;
     }
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
