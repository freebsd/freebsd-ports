--- vio/viossl.c.orig	2015-06-20 10:21:51 UTC
+++ vio/viossl.c
@@ -392,8 +392,10 @@ static int ssl_do(struct st_VioSSLFd *pt
   SSL_SESSION_set_timeout(SSL_get_session(ssl), timeout);
   SSL_set_fd(ssl, sd);
 #ifndef HAVE_YASSL
+#ifdef SSL_OP_NO_COMPRESSION
   SSL_set_options(ssl, SSL_OP_NO_COMPRESSION);
 #endif
+#endif
 
   /*
     Since yaSSL does not support non-blocking send operations, use
