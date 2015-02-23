From 77e87e41613c17ce6fdd8e9521d378566649937f Mon Sep 17 00:00:00 2001
From: Heiko Becker <heirecka@exherbo.org>
Date: Mon, 20 Oct 2014 14:46:34 +0200
Subject: [PATCH] [qca-ossl] Fix build with libressl

libressl removed the SSL Compression functionality (which might
be considered insecure) and thus also compress_meth.
SSL_SESSION_get_compress_id is just a stub in libressl which always
returns 0 and in openssl it returns compress_meth.
---
 plugins/qca-ossl/qca-ossl.cpp | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git plugins/qca-ossl/qca-ossl.cpp plugins/qca-ossl/qca-ossl.cpp
index 783a20d..66f5381 100644
--- plugins/qca-ossl/qca-ossl.cpp
+++ plugins/qca-ossl/qca-ossl.cpp
@@ -5801,7 +5801,7 @@ public:
 	{
 		SessionInfo sessInfo;
 
-		sessInfo.isCompressed = (0 != ssl->session->compress_meth);
+		sessInfo.isCompressed = (0 != SSL_SESSION_get_compress_id(ssl->session));
 
 		if (ssl->version == TLS1_VERSION)
 			sessInfo.version = TLS::TLS_v1;
-- 
2.1.3

