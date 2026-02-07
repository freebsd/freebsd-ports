--- third_party/perfetto/src/tracing/track.cc.orig	2025-01-27 17:37:37 UTC
+++ third_party/perfetto/src/tracing/track.cc
@@ -60,8 +60,9 @@ protos::gen::TrackDescriptor ProcessTrack::Serialize()
   auto desc = Track::Serialize();
   auto pd = desc.mutable_process();
   pd->set_pid(static_cast<int32_t>(pid));
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   std::string cmdline;
   if (base::ReadFile("/proc/self/cmdline", &cmdline)) {
     // Since cmdline is a zero-terminated list of arguments, this ends up
@@ -170,7 +171,7 @@ uint64_t GetProcessStartTime() {
 namespace {
 
 uint64_t GetProcessStartTime() {
-#if !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN)
+#if !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) && !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   std::string stat;
   if (!base::ReadFile("/proc/self/stat", &stat))
     return 0u;
