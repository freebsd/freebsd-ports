--- core/thread.h.orig	2023-05-24 17:03:47 UTC
+++ core/thread.h
@@ -8,6 +8,11 @@
 #if !defined(_WIN32)
   #include <pthread.h>
   #include <sched.h>
+  #if __FreeBSD__ <= 12
+    #include <sys/cpuset.h>
+    struct _cpuset;
+    typedef struct _cpuset cpu_set_t;
+  #endif
   #if defined(__APPLE__)
     #include <mach/thread_policy.h>
   #endif
@@ -130,7 +135,7 @@ OIDN_NAMESPACE_BEGIN
     std::vector<GROUP_AFFINITY> oldAffinities; // original thread affinities
   };
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 
   // -----------------------------------------------------------------------------------------------
   // ThreadAffinity: Linux
@@ -153,8 +158,8 @@ OIDN_NAMESPACE_BEGIN
     void restore(int threadIndex);
 
   private:
-    std::vector<cpu_set_t> affinities;    // thread affinities
-    std::vector<cpu_set_t> oldAffinities; // original thread affinities
+    std::vector<cpuset_t> affinities;    // thread affinities
+    std::vector<cpuset_t> oldAffinities; // original thread affinities
   };
 
 #elif defined(__APPLE__)
