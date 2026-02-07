--- basictcp.cpp.orig	2012-01-01 11:36:27 UTC
+++ basictcp.cpp
@@ -102,10 +102,18 @@ int base_tcp::ConnectTLS()
   m_sslMeth = NULL;
   m_sslCtx = NULL;
   m_ssl = NULL;
-  m_sslMeth = SSLv2_client_method();
+#ifndef OPENSSL_NO_SSL3
+  m_sslMeth = SSLv3_client_method();
+#else
+  m_sslMeth = SSLv23_client_method();
+#endif
   if(m_sslMeth == NULL)
   {
-    fprintf(stderr, "Can't get SSLv2_client_method.\n");
+#ifndef OPENSSL_NO_SSL3
+    fprintf(stderr, "Can't get SSLv3_client_method.\n");
+#else
+    fprintf(stderr, "Can't get SSLv23_client_method.\n");
+#endif
     return 2;
   }
   m_sslCtx = SSL_CTX_new(m_sslMeth);
