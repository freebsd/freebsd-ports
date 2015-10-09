--- ck_ssl.c.orig	2011-07-06 15:03:32.000000000 +0200
+++ ck_ssl.c	2015-10-03 14:42:36.360598285 +0200
@@ -1054,11 +1054,15 @@ ssl_display_comp(SSL * ssl)
     if (ssl == NULL)
         return;
 
+#ifndef OPENSSL_NO_COMP
     if (ssl->expand == NULL || ssl->expand->meth == NULL)
+#endif
         printf("Compression: None\r\n");
+#ifndef OPENSSL_NO_COMP
     else {
         printf("Compression: %s\r\n",ssl->expand->meth->name);
     }
+#endif
 }
 
 int
@@ -1483,9 +1487,13 @@ the build.\r\n\r\n");
         }
         debug(F110,"ssl_rnd_file",ssl_rnd_file,0);
 
+#ifndef OPENSSL_NO_EGD
         rc1 = RAND_egd(ssl_rnd_file);
         debug(F111,"ssl_once_init","RAND_egd()",rc1);
-        if ( rc1 <= 0 ) {
+        if ( rc1 <= 0 ) 
+#endif
+	{
+
             rc2 = RAND_load_file(ssl_rnd_file, -1);
             debug(F111,"ssl_once_init","RAND_load_file()",rc1);
         }
@@ -1579,10 +1587,12 @@ ssl_tn_init(mode) int mode;
             /* This can fail because we do not have RSA available */
             if ( !ssl_ctx ) {
                 debug(F110,"ssl_tn_init","SSLv23_client_method failed",0);
+#ifndef OPENSSL_NO_SSL3
                 ssl_ctx=(SSL_CTX *)SSL_CTX_new(SSLv3_client_method());
             }
             if ( !ssl_ctx ) {
                 debug(F110,"ssl_tn_init","SSLv3_client_method failed",0);
+#endif
                 last_ssl_mode = -1;
                 return(0);
             }
@@ -1593,8 +1603,10 @@ ssl_tn_init(mode) int mode;
             /* This can fail because we do not have RSA available */
             if ( !tls_ctx ) {
                 debug(F110,"ssl_tn_init","SSLv23_client_method failed",0);
+#ifndef OPENSSL_NO_SSL3
                 tls_ctx=(SSL_CTX *)SSL_CTX_new(SSLv3_client_method());
             }
+#endif /* OPENSSL_NO_SSL3 */
 #endif /* COMMENT */
             if ( !tls_ctx ) {
                 debug(F110,"ssl_tn_init","TLSv1_client_method failed",0);
@@ -1611,10 +1623,12 @@ ssl_tn_init(mode) int mode;
             /* This can fail because we do not have RSA available */
             if ( !ssl_ctx ) {
                 debug(F110,"ssl_tn_init","SSLv23_server_method failed",0);
+#ifndef OPENSSL_NO_SSL3
                 ssl_ctx=(SSL_CTX *)SSL_CTX_new(SSLv3_server_method());
             }
             if ( !ssl_ctx ) {
                 debug(F110,"ssl_tn_init","SSLv3_server_method failed",0);
+#endif
                 last_ssl_mode = -1;
                 return(0);
             }
@@ -2161,7 +2175,9 @@ ssl_http_init(hostname) char * hostname;
         /* This can fail because we do not have RSA available */
         if ( !tls_http_ctx ) {
             debug(F110,"ssl_http_init","SSLv23_client_method failed",0);
+#ifndef OPENSSL_NO_SSL3
             tls_http_ctx=(SSL_CTX *)SSL_CTX_new(SSLv3_client_method());
+#endif
         }
 #endif /* COMMENT */
         if ( !tls_http_ctx ) {
