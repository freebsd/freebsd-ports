Backport of Perfetto's FreeBSD support (upstream 81c39c7f82, Perfetto
v53) to the Perfetto that Dart 3.13 pins (series 1001). Drop it once
Dart pins Perfetto v53 or later.
--- third_party/perfetto/src/include/perfetto/base/build_config.h.orig	2026-09-29 08:00:52 UTC
+++ third_party/perfetto/src/include/perfetto/base/build_config.h
@@ -51,7 +51,9 @@
 #define PERFETTO_BUILDFLAG_DEFINE_PERFETTO_OS_MAC() 1
 #define PERFETTO_BUILDFLAG_DEFINE_PERFETTO_OS_IOS() 0
 #endif
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
+// FreeBSD is built as a Linux variant (as in the Dart VM); see the
+// __FreeBSD__ checks for where the two differ.
 #define PERFETTO_BUILDFLAG_DEFINE_PERFETTO_OS_ANDROID() 0
 #define PERFETTO_BUILDFLAG_DEFINE_PERFETTO_OS_LINUX() 1
 #define PERFETTO_BUILDFLAG_DEFINE_PERFETTO_OS_WIN() 0
