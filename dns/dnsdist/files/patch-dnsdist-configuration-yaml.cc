--- dnsdist-configuration-yaml.cc.orig	2025-10-20 17:09:15 UTC
+++ dnsdist-configuration-yaml.cc
@@ -1145,7 +1145,7 @@ bool loadConfigurationFromFile(const std::string& file
 
     for (const auto& cache : globalConfig.packet_caches) {
       DNSDistPacketCache::CacheSettings settings{
-        .d_maxEntries = cache.size,
+        .d_maxEntries = static_cast<size_t>(cache.size),
         .d_maxTTL = cache.max_ttl,
         .d_minTTL = cache.min_ttl,
         .d_tempFailureTTL = cache.temporary_failure_ttl,
