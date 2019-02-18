--- common/thread.cpp.orig	2019-02-18 06:42:30 UTC
+++ common/thread.cpp
@@ -14,6 +14,8 @@
 // limitations under the License.                                           //
 // ======================================================================== //
 
+#include <pthread_np.h>
+
 #if defined(_MSC_VER)
   #pragma warning (disable : 4146) // unary minus operator applied to unsigned type, result still unsigned
 #endif
@@ -132,7 +135,7 @@ namespace oidn {
       OIDN_WARNING("SetThreadGroupAffinity failed");
   }
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 
   // --------------------------------------------------------------------------
   // ThreadAffinity - Linux
@@ -176,7 +179,7 @@ namespace oidn {
 
     for (size_t i = 0; i < threadIds.size(); ++i)
     {
-      cpu_set_t affinity;
+      cpuset_t affinity;
       CPU_ZERO(&affinity);
       CPU_SET(threadIds[i], &affinity);
 
@@ -193,7 +196,7 @@ namespace oidn {
     const pthread_t thread = pthread_self();
 
     // Save the current affinity
-    if (pthread_getaffinity_np(thread, sizeof(cpu_set_t), &oldAffinities[threadIndex]) != 0)
+    if (pthread_getaffinity_np(thread, sizeof(cpuset_t), &oldAffinities[threadIndex]) != 0)
     {
       OIDN_WARNING("pthread_getaffinity_np failed");
       oldAffinities[threadIndex] = affinities[threadIndex];
@@ -201,7 +204,7 @@ namespace oidn {
     }
 
     // Set the new affinity
-    if (pthread_setaffinity_np(thread, sizeof(cpu_set_t), &affinities[threadIndex]) != 0)
+    if (pthread_setaffinity_np(thread, sizeof(cpuset_t), &affinities[threadIndex]) != 0)
       OIDN_WARNING("pthread_setaffinity_np failed");
   }
 
@@ -213,7 +216,7 @@ namespace oidn {
     const pthread_t thread = pthread_self();
 
     // Restore the original affinity
-    if (pthread_setaffinity_np(thread, sizeof(cpu_set_t), &oldAffinities[threadIndex]) != 0)
+    if (pthread_setaffinity_np(thread, sizeof(cpuset_t), &oldAffinities[threadIndex]) != 0)
       OIDN_WARNING("pthread_setaffinity_np failed");
   }
 
