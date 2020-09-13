--- common/thread.h.orig	2020-09-11 17:36:51 UTC
+++ common/thread.h
@@ -130,8 +130,10 @@ namespace oidn {
     void restore(int threadIndex);
   };
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 
+#include <sys/cpuset.h>
+
   // ---------------------------------------------------------------------------
   // ThreadAffinity: Linux
   // ---------------------------------------------------------------------------
@@ -139,8 +141,8 @@ namespace oidn {
   class ThreadAffinity : public Verbose
   {
   private:
-    std::vector<cpu_set_t> affinities;    // thread affinities
-    std::vector<cpu_set_t> oldAffinities; // original thread affinities
+    std::vector<cpuset_t> affinities;    // thread affinities
+    std::vector<cpuset_t> oldAffinities; // original thread affinities
 
   public:
     ThreadAffinity(int numThreadsPerCore = INT_MAX, int verbose = 0);
