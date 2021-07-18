--- third_party/perfetto/src/tracing/ipc/default_socket.cc.orig	2021-04-14 01:15:27 UTC
+++ third_party/perfetto/src/tracing/ipc/default_socket.cc
@@ -35,7 +35,8 @@ const char* kRunPerfettoBaseDir = "/run/perfetto/";
 bool UseRunPerfettoBaseDir() {
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) ||   \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   // Note that the trailing / in |kRunPerfettoBaseDir| ensures we are checking
   // against a directory, not a file.
   int res = PERFETTO_EINTR(access(kRunPerfettoBaseDir, X_OK));
