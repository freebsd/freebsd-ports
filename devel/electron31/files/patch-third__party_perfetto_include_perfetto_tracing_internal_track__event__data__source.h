--- third_party/perfetto/include/perfetto/tracing/internal/track_event_data_source.h.orig	2024-08-19 05:26:12 UTC
+++ third_party/perfetto/include/perfetto/tracing/internal/track_event_data_source.h
@@ -328,13 +328,13 @@ class TrackEventDataSource
   }
 
   static void Flush() {
-    Base::template Trace([](typename Base::TraceContext ctx) { ctx.Flush(); });
+    Base::Trace([](typename Base::TraceContext ctx) { ctx.Flush(); });
   }
 
   // Determine if *any* tracing category is enabled.
   static bool IsEnabled() {
     bool enabled = false;
-    Base::template CallIfEnabled(
+    Base::CallIfEnabled(
         [&](uint32_t /*instances*/) { enabled = true; });
     return enabled;
   }
@@ -349,7 +349,7 @@ class TrackEventDataSource
   static bool IsDynamicCategoryEnabled(
       const DynamicCategory& dynamic_category) {
     bool enabled = false;
-    Base::template Trace([&](typename Base::TraceContext ctx) {
+    Base::Trace([&](typename Base::TraceContext ctx) {
       enabled = enabled || IsDynamicCategoryEnabled(&ctx, dynamic_category);
     });
     return enabled;
@@ -496,7 +496,7 @@ class TrackEventDataSource
                                  const protos::gen::TrackDescriptor& desc) {
     PERFETTO_DCHECK(track.uuid == desc.uuid());
     TrackRegistry::Get()->UpdateTrack(track, desc.SerializeAsString());
-    Base::template Trace([&](typename Base::TraceContext ctx) {
+    Base::Trace([&](typename Base::TraceContext ctx) {
       TrackEventInternal::WriteTrackDescriptor(
           track, ctx.tls_inst_->trace_writer.get(), ctx.GetIncrementalState(),
           *ctx.GetCustomTlsState(), TrackEventInternal::GetTraceTime());
@@ -1047,7 +1047,7 @@ class TrackEventDataSource
                                  Lambda lambda) PERFETTO_ALWAYS_INLINE {
     using CatTraits = CategoryTraits<CategoryType>;
     if (CatTraits::kIsDynamic) {
-      Base::template TraceWithInstances(instances, std::move(lambda));
+      Base::TraceWithInstances(instances, std::move(lambda));
     } else {
       Base::template TraceWithInstances<CategoryTracePointTraits>(
           instances, std::move(lambda), {CatTraits::GetStaticIndex(category)});
@@ -1061,7 +1061,7 @@ class TrackEventDataSource
       const TrackType& track,
       std::function<void(protos::pbzero::TrackDescriptor*)> callback) {
     TrackRegistry::Get()->UpdateTrack(track, std::move(callback));
-    Base::template Trace([&](typename Base::TraceContext ctx) {
+    Base::Trace([&](typename Base::TraceContext ctx) {
       TrackEventInternal::WriteTrackDescriptor(
           track, ctx.tls_inst_->trace_writer.get(), ctx.GetIncrementalState(),
           *ctx.GetCustomTlsState(), TrackEventInternal::GetTraceTime());
