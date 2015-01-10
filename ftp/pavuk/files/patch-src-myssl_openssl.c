--- src/myssl_openssl.c.orig	2005-08-15 08:59:30 UTC
+++ src/myssl_openssl.c
@@ -543,12 +543,16 @@ bufio *my_ssl_do_connect(doc * docp, buf
 
   switch (cfg.ssl_version)
   {
+#ifndef OPENSSL_NO_SSL2
   case 2:
     method = SSLv2_client_method();
     break;
+#endif
+#ifndef OPENSSL_NO_SSL3_METHOD
   case 3:
     method = SSLv3_client_method();
     break;
+#endif
 #ifdef WITH_SSL_TLS1
   case 4:
     method = TLSv1_client_method();
