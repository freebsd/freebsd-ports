--- urbackupclient/lin_tokens.cpp.orig	2022-08-21 08:45:31 UTC
+++ urbackupclient/lin_tokens.cpp
@@ -34,7 +34,7 @@ TokenCache::TokenCache()
 };
 
 TokenCache::TokenCache()
-: token_cache(NULL)
+: token_cache()
 {
 }
 
