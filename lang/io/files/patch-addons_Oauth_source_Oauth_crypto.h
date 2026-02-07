--- addons/Oauth/source/Oauth/crypto.h.orig	2017-09-14 12:33:11 UTC
+++ addons/Oauth/source/Oauth/crypto.h
@@ -16,7 +16,7 @@ struct md5_context
 
 struct sha1_context
 {
-	unsigned long state[5];
+	uint32_t state[5];
 	unsigned long count[2];
 	unsigned char buffer[64];
 };
