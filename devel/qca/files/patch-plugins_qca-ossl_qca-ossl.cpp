--- qca-ossl.cpp.orig	2014-11-06 09:15:45.000000000 +0100
+++ qca-ossl.cpp	2015-02-23 10:25:54.952326743 +0100
@@ -5801,7 +5801,11 @@
 	{
 		SessionInfo sessInfo;
 
+#ifndef OPENSSL_NO_COMP
 		sessInfo.isCompressed = (0 != ssl->session->compress_meth);
+#else
+		sessInfo.isCompressed = 0;
+#endif
 
 		if (ssl->version == TLS1_VERSION)
 			sessInfo.version = TLS::TLS_v1;
