--- google/cloud/storage/internal/grpc/metrics_exporter_options.cc.orig	2026-11-04 06:54:35 UTC
+++ google/cloud/storage/internal/grpc/metrics_exporter_options.cc
@@ -37,7 +37,7 @@ auto ByName(opentelemetry::sdk::resource::ResourceAttr
             std::string const& name, std::string default_value) {
   auto const l = attributes.find(name);
   if (l == attributes.end()) return default_value;
-  return std::get<std::string>(l->second);
+  return opentelemetry::nostd::get<std::string>(l->second);
 }
 
 }  // namespace
