--- tcp.cpp.orig	2012-01-01 06:24:45.000000000 -0500
+++ tcp.cpp	2015-03-23 17:06:52.611229000 -0400
@@ -178,10 +178,10 @@
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
