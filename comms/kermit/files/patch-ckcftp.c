--- ckcftp.c.orig	2011-07-14 18:17:30.000000000 +0200
+++ ckcftp.c	2015-10-03 14:48:01.112575165 +0200
@@ -10196,15 +10196,21 @@ ssl_auth() {
 #define SSL_OP_DONT_INSERT_EMPTY_FRAGMENTS 0L
 #endif
     if (auth_type && !strcmp(auth_type,"TLS")) {
+#ifndef OPENSSL_NO_SSL3
         ssl_ftp_ctx=SSL_CTX_new(SSLv3_client_method());
+#endif
         if (!ssl_ftp_ctx)
           return(0);
         SSL_CTX_set_options(ssl_ftp_ctx,
                             SSL_OP_SINGLE_DH_USE|SSL_OP_EPHEMERAL_RSA
                             );
     } else {
+#ifndef OPENSSL_NO_SSL3
         ssl_ftp_ctx = SSL_CTX_new(ftp_bug_use_ssl_v2 ? SSLv23_client_method() : 
                                   SSLv3_client_method());
+#else
+        ssl_ftp_ctx = SSL_CTX_new(SSLv23_client_method());
+#endif
         if (!ssl_ftp_ctx)
           return(0);
         SSL_CTX_set_options(ssl_ftp_ctx,
