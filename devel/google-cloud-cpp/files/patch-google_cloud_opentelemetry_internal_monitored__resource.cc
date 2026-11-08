--- google/cloud/opentelemetry/internal/monitored_resource.cc.orig	2026-11-04 06:54:35 UTC
+++ google/cloud/opentelemetry/internal/monitored_resource.cc
@@ -234,7 +234,7 @@ std::string AsString(
 
 std::string AsString(
     opentelemetry::sdk::common::OwnedAttributeValue const& attribute) {
-  return std::visit(AsStringVisitor{}, attribute);
+  return opentelemetry::nostd::visit(AsStringVisitor{}, attribute);
 }
 
 MonitoredResource ToMonitoredResource(
