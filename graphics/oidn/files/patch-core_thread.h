--- core/thread.h.orig	2024-06-14 23:02:44 UTC
+++ core/thread.h
@@ -9,6 +9,11 @@
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
@@ -135,7 +140,7 @@ OIDN_NAMESPACE_BEGIN
     std::vector<GROUP_AFFINITY> oldAffinities; // original thread affinities
   };
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 
   // -----------------------------------------------------------------------------------------------
   // ThreadAffinity: Linux
@@ -161,8 +166,8 @@ OIDN_NAMESPACE_BEGIN
     // Parses a list of numbers from a file in /sys/devices/system
     static std::vector<int> parseList(const std::string& filename);
 
-    std::vector<cpu_set_t> affinities;    // thread affinities
-    std::vector<cpu_set_t> oldAffinities; // original thread affinities
+    std::vector<cpuset_t> affinities;    // thread affinities
+    std::vector<cpuset_t> oldAffinities; // original thread affinities
   };
 
 #elif defined(__APPLE__)
