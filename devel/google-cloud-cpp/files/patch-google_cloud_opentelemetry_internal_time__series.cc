--- google/cloud/opentelemetry/internal/time_series.cc.orig	2026-11-04 06:54:35 UTC
+++ google/cloud/opentelemetry/internal/time_series.cc
@@ -41,10 +41,10 @@ google::monitoring::v3::TypedValue ToValue(
 google::monitoring::v3::TypedValue ToValue(
     opentelemetry::sdk::metrics::ValueType value) {
   google::monitoring::v3::TypedValue proto;
-  if (std::holds_alternative<double>(value)) {
-    proto.set_double_value(std::get<double>(value));
+  if (opentelemetry::nostd::holds_alternative<double>(value)) {
+    proto.set_double_value(opentelemetry::nostd::get<double>(value));
   } else {
-    proto.set_int64_value(std::get<std::int64_t>(value));
+    proto.set_int64_value(opentelemetry::nostd::get<std::int64_t>(value));
   }
   return proto;
 }
@@ -63,9 +63,9 @@ double AsDouble(opentelemetry::sdk::metrics::ValueType
 }
 
 double AsDouble(opentelemetry::sdk::metrics::ValueType const& v) {
-  return std::holds_alternative<double>(v)
-             ? std::get<double>(v)
-             : static_cast<double>(std::get<std::int64_t>(v));
+  return opentelemetry::nostd::holds_alternative<double>(v)
+             ? opentelemetry::nostd::get<double>(v)
+             : static_cast<double>(opentelemetry::nostd::get<std::int64_t>(v));
 }
 
 std::vector<google::monitoring::v3::CreateTimeSeriesRequest> ToRequestsHelper(
@@ -127,7 +127,7 @@ void ToTimeSeriesHelper(
             return std::nullopt;
           }
         };
-        auto ts = std::visit(Visitor{metric_data}, pda.point_data);
+        auto ts = opentelemetry::nostd::visit(Visitor{metric_data}, pda.point_data);
         if (!ts) continue;
         ts->set_unit(metric_data.instrument_descriptor.unit_);
         ts_collector_fn(metric_data, pda, *std::move(ts));
