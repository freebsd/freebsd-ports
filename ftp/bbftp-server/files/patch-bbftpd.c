--- bbftpd.c.orig	2005-05-03 08:43:34 UTC
+++ bbftpd.c
@@ -842,10 +842,12 @@ main (argc,argv,envp)
         char    buffrand[NBITSINKEY] ;
         struct timeval tp ;
         unsigned int seed ;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
         /*
         ** Load the error message from the crypto lib
         */
         ERR_load_crypto_strings() ;
+#endif
         /*
         ** Initialize the buffrand buffer which is giong to be used to initialize the 
         ** random generator
