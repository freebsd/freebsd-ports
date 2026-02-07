--- core/thread.cpp.orig	2024-06-14 23:02:44 UTC
+++ core/thread.cpp
@@ -1,11 +1,13 @@
 // Copyright 2009 Intel Corporation
 // SPDX-License-Identifier: Apache-2.0
 
+#include <pthread_np.h>
+
 #if defined(_MSC_VER)
   #pragma warning (disable : 4146) // unary minus operator applied to unsigned type, result still unsigned
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
   #include <sched.h>
   #include <unordered_set>
 #elif defined(__APPLE__)
@@ -125,7 +127,7 @@ OIDN_NAMESPACE_BEGIN
       printWarning("SetThreadGroupAffinity failed");
   }
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 
   // -----------------------------------------------------------------------------------------------
   // ThreadAffinity: Linux
@@ -179,7 +181,7 @@ OIDN_NAMESPACE_BEGIN
 
     for (size_t i = 0; i < threadIDs.size(); ++i)
     {
-      cpu_set_t affinity;
+      cpuset_t affinity;
       CPU_ZERO(&affinity);
       CPU_SET(threadIDs[i], &affinity);
 
@@ -196,7 +198,7 @@ OIDN_NAMESPACE_BEGIN
     const pthread_t thread = pthread_self();
 
     // Save the current affinity
-    if (pthread_getaffinity_np(thread, sizeof(cpu_set_t), &oldAffinities[threadIndex]) != 0)
+    if (pthread_getaffinity_np(thread, sizeof(cpuset_t), &oldAffinities[threadIndex]) != 0)
     {
       printWarning("pthread_getaffinity_np failed");
       oldAffinities[threadIndex] = affinities[threadIndex];
@@ -204,7 +206,7 @@ OIDN_NAMESPACE_BEGIN
     }
 
     // Set the new affinity
-    if (pthread_setaffinity_np(thread, sizeof(cpu_set_t), &affinities[threadIndex]) != 0)
+    if (pthread_setaffinity_np(thread, sizeof(cpuset_t), &affinities[threadIndex]) != 0)
       printWarning("pthread_setaffinity_np failed");
   }
 
@@ -216,7 +218,7 @@ OIDN_NAMESPACE_BEGIN
     const pthread_t thread = pthread_self();
 
     // Restore the original affinity
-    if (pthread_setaffinity_np(thread, sizeof(cpu_set_t), &oldAffinities[threadIndex]) != 0)
+    if (pthread_setaffinity_np(thread, sizeof(cpuset_t), &oldAffinities[threadIndex]) != 0)
       printWarning("pthread_setaffinity_np failed");
   }
 
