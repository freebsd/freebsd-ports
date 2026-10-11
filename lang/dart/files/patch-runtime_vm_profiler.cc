Fix building without Perfetto (series 0001): define
Profiler::IsolateShutdown() and IsolateGroupShutdown() whenever the
profiler is built, not only with Perfetto.
Upstream: landed in dart-lang/sdk as e4dec8c8967 (#64525), after 3.13.
--- runtime/vm/profiler.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/vm/profiler.cc
@@ -2081,20 +2081,24 @@ void SampleBlockProcessor::Shutdown() {
   processor_thread_id_ = OSThread::kInvalidThreadJoinId;
   ASSERT(!thread_running_);
 }
+#endif  // defined(SUPPORT_TIMELINE) && defined(SUPPORT_PERFETTO)
 
+// Isolate.cc calls these whenever the profiler is included, which does not
+// require Perfetto support.
 void Profiler::IsolateShutdown(Isolate* isolate) {
   FlushSampleBlocks(isolate);
   NOT_IN_PRECOMPILED(Timeline::DrainCompletedSampleBlocksIntoRecorder(isolate));
 }
 
 void Profiler::IsolateGroupShutdown(IsolateGroup* isolate_group) {
-#if defined(SUPPORT_TIMELINE)
+#if defined(SUPPORT_TIMELINE) && defined(SUPPORT_PERFETTO)
   if (config_.enabled && config_.stream_to_timeline) {
     Timeline::NotifyAboutIsolateGroupShutdown(isolate_group);
   }
-#endif  // defined(SUPPORT_TIMELINE)
+#endif  // defined(SUPPORT_TIMELINE) && defined(SUPPORT_PERFETTO)
 }
 
+#if defined(SUPPORT_TIMELINE) && defined(SUPPORT_PERFETTO)
 void SampleBlockProcessor::ThreadMain(uword parameters) {
   ASSERT(initialized_);
   {
