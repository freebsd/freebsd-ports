--- google/cloud/opentelemetry/internal/recordable.cc.orig	2026-11-04 06:54:35 UTC
+++ google/cloud/opentelemetry/internal/recordable.cc
@@ -207,7 +207,7 @@ void AddAttributeImpl(
     std::size_t limit) {
   auto* proto = ProtoOrDrop(attributes, key, limit);
   if (proto) {
-    std::visit(AttributeVisitor{*proto}, value);
+    opentelemetry::nostd::visit(AttributeVisitor{*proto}, value);
   } else {
     attributes.set_dropped_attributes_count(
         attributes.dropped_attributes_count() + 1);
