--- common/sys/thread.cpp.orig	2016-05-20 05:45:13 UTC
+++ common/sys/thread.cpp
@@ -239,6 +239,29 @@ namespace embree
 #endif
 
 ////////////////////////////////////////////////////////////////////////////////
+/// FreeBSD Platform
+////////////////////////////////////////////////////////////////////////////////
+
+#if defined(__FreeBSD__)
+
+#include <pthread_np.h>
+
+namespace embree
+{
+  /*! set affinity of the calling thread */
+  void setAffinity(ssize_t affinity)
+  {
+    cpuset_t cset;
+    CPU_ZERO(&cset);
+    CPU_SET(affinity, &cset);
+
+    if (pthread_setaffinity_np(pthread_self(), sizeof(cset), &cset) != 0)
+      WARNING("pthread_setaffinity_np failed"); // on purpose only a warning
+  }
+}
+#endif
+
+////////////////////////////////////////////////////////////////////////////////
 /// MacOSX Platform
 ////////////////////////////////////////////////////////////////////////////////
 
@@ -291,7 +314,8 @@ namespace embree
   {
     _mm_setcsr(_mm_getcsr() | /*FTZ:*/ (1<<15) | /*DAZ:*/ (1<<6));
 
-#if !defined(__LINUX__)
+#if defined(__MACOSX__)
+    /*! Mac OS X does not support setting affinity at thread creation time */
     if (parg->affinity >= 0)
 	setAffinity(parg->affinity);
 #endif
@@ -320,7 +344,15 @@ namespace embree
       cpu_set_t cset;
       CPU_ZERO(&cset);
       CPU_SET(mapThreadID(threadID), &cset);
-      if (pthread_setaffinity_np(*tid,sizeof(cpu_set_t),&cset))
+      if (pthread_setaffinity_np(*tid, sizeof(cset), &cset))
+        WARNING("pthread_setaffinity_np failed"); // on purpose only a warning
+    }
+#elif defined(__FreeBSD__)
+    if (threadID >= 0) {
+      cpuset_t cset;
+      CPU_ZERO(&cset);
+      CPU_SET(threadID, &cset);
+      if (pthread_setaffinity_np(*tid, sizeof(cset), &cset))
         WARNING("pthread_setaffinity_np failed"); // on purpose only a warning
     }
 #endif
