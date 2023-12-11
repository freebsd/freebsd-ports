--- base/trace_event/trace_log.cc.orig	2023-10-19 19:57:58 UTC
+++ base/trace_event/trace_log.cc
@@ -2190,8 +2190,13 @@ void TraceLog::SetTraceBufferForTesting(
 #if BUILDFLAG(USE_PERFETTO_CLIENT_LIBRARY)
 void TraceLog::OnSetup(const perfetto::DataSourceBase::SetupArgs& args) {
   AutoLock lock(track_event_lock_);
+#if defined(__clang__) && (__clang_major__ >= 16)
   track_event_sessions_.emplace_back(args.internal_instance_index, *args.config,
                                      args.backend_type);
+#else
+  track_event_sessions_.emplace_back(TrackEventSession{args.internal_instance_index, *args.config,
+                                     args.backend_type});
+#endif
 }
 
 void TraceLog::OnStart(const perfetto::DataSourceBase::StartArgs&) {
