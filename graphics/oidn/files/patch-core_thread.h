--- core/thread.h.orig	2023-05-24 17:03:47 UTC
+++ core/thread.h
@@ -130,7 +130,7 @@ OIDN_NAMESPACE_BEGIN
     std::vector<GROUP_AFFINITY> oldAffinities; // original thread affinities
   };
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 
   // -----------------------------------------------------------------------------------------------
   // ThreadAffinity: Linux
@@ -153,8 +153,8 @@ OIDN_NAMESPACE_BEGIN
     void restore(int threadIndex);
 
   private:
-    std::vector<cpu_set_t> affinities;    // thread affinities
-    std::vector<cpu_set_t> oldAffinities; // original thread affinities
+    std::vector<cpuset_t> affinities;    // thread affinities
+    std::vector<cpuset_t> oldAffinities; // original thread affinities
   };
 
 #elif defined(__APPLE__)
