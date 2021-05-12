--- third_party/perfetto/include/perfetto/ext/base/thread_utils.h.orig	2021-04-14 01:15:26 UTC
+++ third_party/perfetto/include/perfetto/ext/base/thread_utils.h
@@ -23,7 +23,8 @@
 
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) ||   \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 #include <pthread.h>
 #include <string.h>
 #include <algorithm>
@@ -37,7 +38,8 @@ namespace base {
 
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) ||   \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 // Sets the "comm" of the calling thread to the first 15 chars of the given
 // string.
 inline bool MaybeSetThreadName(const std::string& name) {
@@ -47,6 +49,9 @@ inline bool MaybeSetThreadName(const std::string& name
 
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
   return pthread_setname_np(buf) == 0;
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+  pthread_set_name_np(pthread_self(), buf);
+  return true;
 #else
   return pthread_setname_np(pthread_self(), buf) == 0;
 #endif
