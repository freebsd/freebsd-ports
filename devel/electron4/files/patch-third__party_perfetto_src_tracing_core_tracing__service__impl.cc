--- third_party/perfetto/src/tracing/core/tracing_service_impl.cc.orig	2019-03-15 06:40:55 UTC
+++ third_party/perfetto/src/tracing/core/tracing_service_impl.cc
@@ -1050,7 +1050,8 @@ void TracingServiceImpl::MaybeSnapshotClocks(
   protos::ClockSnapshot* clock_snapshot = packet.mutable_clock_snapshot();
 
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_MACOSX) && \
-    !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN)
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   struct {
     clockid_t id;
     protos::ClockSnapshot::Clock::Type type;
