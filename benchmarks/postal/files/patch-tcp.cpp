--- tcp.cpp.orig	2012-01-01 11:24:45 UTC
+++ tcp.cpp
@@ -178,10 +178,18 @@ int tcp::ConnectTLS()
 #ifdef USE_OPENSSL
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
     error();
     return 2;
   }
