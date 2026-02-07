--- connecttoserver.c.orig	2013-02-07 10:42:46 UTC
+++ connecttoserver.c
@@ -517,6 +517,7 @@ int connectviapassword() 
 #ifdef WITH_SSL
     RSA     *hisrsa ;
     int lenrsa ;
+    BIGNUM *n, *e;
 #endif
     /*
     ** Get the socket
@@ -629,33 +630,35 @@ int connectviapassword() 
         /*
         ** Getting BIGNUM structures to store the key and exponent
         */
-        if ( (hisrsa->n = BN_new()) == NULL) {
+        n = BN_new();
+        e = BN_new();
+        if (n == NULL || e == NULL) {
             free(readbuffer) ;
             close(tmpctrlsock) ;
             printmessage(stderr,CASE_ERROR,56,timestamp,"Error reading encrypted message : %s (%s)\n","getting BIGNUM",(char *) ERR_error_string(ERR_get_error(),NULL)) ;
             return -1 ;
         }
-        if ( (hisrsa->e = BN_new()) == NULL) { 
-            free(readbuffer) ;
-            close(tmpctrlsock) ;
-            printmessage(stderr,CASE_ERROR,56,timestamp,"Error reading encrypted message : %s (%s)\n","getting BIGNUM",(char *) ERR_error_string(ERR_get_error(),NULL)) ;
-            return -1 ;
-        }
         /*
         ** Copy the key and exponent received
         */
-        if ( BN_mpi2bn(pubkey,lenkey,hisrsa->n) == NULL ) {
+        if ( BN_mpi2bn(pubkey,lenkey,n) == NULL ) {
             free(readbuffer) ;
             close(tmpctrlsock) ;
             printmessage(stderr,CASE_ERROR,56,timestamp,"Error reading encrypted message : %s (%s)\n","copying pubkey",(char *) ERR_error_string(ERR_get_error(),NULL)) ;
             return -1 ;
         }
-        if ( BN_mpi2bn(pubexponent,lenexpo,hisrsa->e) == NULL ) {
+        if ( BN_mpi2bn(pubexponent,lenexpo,e) == NULL ) {
             free(readbuffer) ;
             close(tmpctrlsock) ;
             printmessage(stderr,CASE_ERROR,56,timestamp,"Error reading encrypted message : %s (%s)\n","copying pubexponent",(char *) ERR_error_string(ERR_get_error(),NULL)) ;
             return -1 ;
         }
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+        hisrsa->n = n;
+        hisrsa->e = e;
+#else
+        RSA_set0_key(hisrsa, n, e, NULL);
+#endif
         lenrsa = RSA_size(hisrsa) ;
        
         if (strlen(username) > lenrsa - 41 ) {
