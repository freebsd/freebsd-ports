--- plugins/qca-ossl/qca-ossl.cpp
+++ plugins/qca-ossl/qca-ossl.cpp
@@ -5801,7 +5801,7 @@ public:
 	{
 		SessionInfo sessInfo;
 
-		sessInfo.isCompressed = (0 != ssl->session->compress_meth);
+		sessInfo.isCompressed = (0 != SSL_SESSION_get_compress_id(ssl->session));
 
 		if (ssl->version == TLS1_VERSION)
 			sessInfo.version = TLS::TLS_v1;
