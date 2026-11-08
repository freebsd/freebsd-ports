--- router/src/rest_host_cache/src/rest_host_cache_entries.cc.orig	2026-07-10 11:18:36 UTC
+++ router/src/rest_host_cache/src/rest_host_cache_entries.cc
@@ -63,7 +63,8 @@ bool RestHostCacheEntries::on_handle_request(
             (remaining_ttl > k_zero_seconds) ? remaining_ttl : k_zero_seconds;
         rapidjson::Value object(rapidjson::kObjectType);
 
-        object.AddMember("secondsRemainingTtl", remaining_ttl.count(),
+        object.AddMember<int64_t>("secondsRemainingTtl",
+                         static_cast<int64_t>(remaining_ttl.count()),
                          allocator);
         object.AddMember<uint64_t>("ttl", e.ttl_.count(), allocator);
         object.AddMember<uint64_t>("cacheHits", e.cache_hits_.load(),
