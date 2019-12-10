--- src/OpenThreads/pthreads/PThread.cpp.orig	2019-07-26 11:54:16 UTC
+++ src/OpenThreads/pthreads/PThread.cpp
@@ -21,6 +21,9 @@
 #include <sys/types.h>
 #include <unistd.h>
 #include <pthread.h>
+#if defined(HAVE_PTHREAD_SETAFFINITY_NP) && defined(__FreeBSD__)
+    #include <pthread_np.h>
+#endif
 #include <limits.h>
 
 #if defined __linux__ || defined __sun || defined __APPLE__ || ANDROID
@@ -113,7 +116,11 @@ namespace OpenThreads
 static void setAffinity(const Affinity& affinity)
 {
     //std::cout<<"setProcessAffinity : "<< affinity.activeCPUs.size() <<std::endl;
+#if defined(__FreeBSD__)
+    cpuset_t cpumask;
+#else
     cpu_set_t cpumask;
+#endif
     CPU_ZERO( &cpumask );
     unsigned int numprocessors = OpenThreads::GetNumberOfProcessors();
     if (affinity)
