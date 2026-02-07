--- lib/VM/Instrumentation/ProcessStats.cpp.orig	2020-09-11 02:29:31 UTC
+++ lib/VM/Instrumentation/ProcessStats.cpp
@@ -69,6 +69,8 @@ ProcessStats::Info getProcessStatSnapshot() {
   va *= PS / 1024;
 #elif defined(__EMSCRIPTEN__)
   rss = va = 0;
+#elif defined(__FreeBSD__)
+  rss = va = 0; // TODO implement getProcessStatSnapshot
 #else
 #error "Unsupported platform"
 #endif
