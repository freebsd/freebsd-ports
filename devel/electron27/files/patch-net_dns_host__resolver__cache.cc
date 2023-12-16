--- net/dns/host_resolver_cache.cc.orig	2023-10-19 19:58:28 UTC
+++ net/dns/host_resolver_cache.cc
@@ -161,7 +161,11 @@ void HostResolverCache::Set(
 
   std::string domain_name = result->domain_name();
   entries_.emplace(
+#if defined(__clang__) && (__clang_major__ >= 16)
       Key(std::move(domain_name), network_anonymization_key),
+#else
+      Key({std::move(domain_name), network_anonymization_key}),
+#endif
       Entry(std::move(result), source, secure, staleness_generation_));
 
   if (entries_.size() > max_entries_) {
