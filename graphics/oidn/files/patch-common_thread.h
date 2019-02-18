--- common/thread.h.orig	2019-02-18 06:37:35 UTC
+++ common/thread.h
@@ -142,7 +142,9 @@ namespace oidn {
     void restore(int threadIndex);
   };
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
+
+#include <sys/cpuset.h>
 
   // --------------------------------------------------------------------------
   // ThreadAffinity - Linux
@@ -151,8 +153,8 @@ namespace oidn {
   class ThreadAffinity
   {
   private:
-    std::vector<cpu_set_t> affinities;    // thread affinities
-    std::vector<cpu_set_t> oldAffinities; // original thread affinities
+    std::vector<cpuset_t> affinities;    // thread affinities
+    std::vector<cpuset_t> oldAffinities; // original thread affinities
 
   public:
     ThreadAffinity(int numThreadsPerCore = INT_MAX);
