--- third_party/perfetto/include/perfetto/ext/base/thread_utils.h.orig	2021-07-15 19:15:50 UTC
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
@@ -41,7 +42,8 @@ namespace base {
 
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) ||   \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 // Sets the "comm" of the calling thread to the first 15 chars of the given
 // string.
 inline bool MaybeSetThreadName(const std::string& name) {
@@ -51,6 +53,9 @@ inline bool MaybeSetThreadName(const std::string& name
 
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
   return pthread_setname_np(buf) == 0;
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+  pthread_set_name_np(pthread_self(), buf);
+  return true;
 #else
   return pthread_setname_np(pthread_self(), buf) == 0;
 #endif
@@ -61,6 +66,8 @@ inline bool GetThreadName(std::string& out_result) {
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
   if (prctl(PR_GET_NAME, buf) != 0)
     return false;
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+  pthread_get_name_np(pthread_self(), buf, sizeof(buf));
 #else
   if (pthread_getname_np(pthread_self(), buf, sizeof(buf)) != 0)
     return false;
