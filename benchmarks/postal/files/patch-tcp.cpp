--- tcp.cpp.orig	2012-01-01 11:24:45 UTC
+++ tcp.cpp
@@ -178,10 +178,10 @@ int tcp::ConnectTLS()
 #ifdef USE_OPENSSL
   m_sslCtx = NULL;
   m_ssl = NULL;
-  m_sslMeth = SSLv2_client_method();
+  m_sslMeth = SSLv3_client_method();
   if(m_sslMeth == NULL)
   {
-    fprintf(stderr, "Can't get SSLv2_client_method.\n");
+    fprintf(stderr, "Can't get SSLv3_client_method.\n");
     error();
     return 2;
   }
