--- third_party/perfetto/src/tracing/platform_posix.cc.orig	2025-01-27 17:37:37 UTC
+++ third_party/perfetto/src/tracing/platform_posix.cc
@@ -110,12 +110,13 @@ std::string PlatformPosix::GetCurrentProcessName() {
 }
 
 std::string PlatformPosix::GetCurrentProcessName() {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   std::string cmdline;
   base::ReadFile("/proc/self/cmdline", &cmdline);
   return cmdline.substr(0, cmdline.find('\0'));
-#elif PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) || PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   return std::string(getprogname());
 #else
   return "unknown_producer";
