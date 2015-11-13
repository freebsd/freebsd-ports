--- common/sys/thread.cpp.orig	2015-09-17 06:11:18 UTC
+++ common/sys/thread.cpp
@@ -171,13 +171,16 @@ namespace embree
 /// Linux Platform
 ////////////////////////////////////////////////////////////////////////////////
 
-#if defined(__LINUX__)
+#if defined(__LINUX__) || defined(__FreeBSD__)
+
+#include <pthread_np.h>
+
 namespace embree
 {
   /*! set affinity of the calling thread */
   void setAffinity(ssize_t affinity)
   {
-    cpu_set_t cset;
+    cpuset_t cset;
     CPU_ZERO(&cset);
     CPU_SET(affinity, &cset);
 
