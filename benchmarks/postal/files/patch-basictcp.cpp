--- basictcp.cpp.orig	2012-01-01 11:36:27 UTC
+++ basictcp.cpp
@@ -102,10 +102,10 @@ int base_tcp::ConnectTLS()
   m_sslMeth = NULL;
   m_sslCtx = NULL;
   m_ssl = NULL;
-  m_sslMeth = SSLv2_client_method();
+  m_sslMeth = SSLv3_client_method();
   if(m_sslMeth == NULL)
   {
-    fprintf(stderr, "Can't get SSLv2_client_method.\n");
+    fprintf(stderr, "Can't get SSLv3_client_method.\n");
     return 2;
   }
   m_sslCtx = SSL_CTX_new(m_sslMeth);
