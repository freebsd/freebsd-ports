--- urbackupclient/lin_tokens.cpp.orig	2025-08-11 17:13:03 UTC
+++ urbackupclient/lin_tokens.cpp
@@ -34,7 +34,7 @@ TokenCache::TokenCache()
 };
 
 TokenCache::TokenCache()
-: token_cache(NULL)
+: token_cache()
 {
 }
 
