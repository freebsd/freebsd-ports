--- third_party/perfetto/src/tracing/core/tracing_service_impl.cc.orig	2019-09-10 11:16:55 UTC
+++ third_party/perfetto/src/tracing/core/tracing_service_impl.cc
@@ -2053,7 +2053,8 @@ void TracingServiceImpl::OnStartTriggersTimeout(Tracin
 
 void TracingServiceImpl::UpdateMemoryGuardrail() {
 #if !PERFETTO_BUILDFLAG(PERFETTO_EMBEDDER_BUILD) && \
-    !PERFETTO_BUILDFLAG(PERFETTO_OS_MACOSX)
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_MACOSX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   uint64_t total_buffer_bytes = 0;
 
   // Sum up all the shared memory buffers.
@@ -2106,7 +2107,8 @@ void TracingServiceImpl::SnapshotClocks(std::vector<Tr
   protos::ClockSnapshot* clock_snapshot = packet.mutable_clock_snapshot();
 
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_MACOSX) && \
-    !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN)
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   struct {
     clockid_t id;
     protos::ClockSnapshot::Clock::Type type;
