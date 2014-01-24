--- src/OpenThreads/pthreads/PThread.cpp.orig	2011-06-24 00:09:26.000000000 +0400
+++ src/OpenThreads/pthreads/PThread.cpp	2012-03-05 05:57:02.886704932 +0400
@@ -21,6 +21,7 @@
 #include <sys/types.h>
 #include <unistd.h>
 #include <pthread.h>
+#include <pthread_np.h>
 #include <limits.h>
 
 #if defined __linux || defined __sun || defined __APPLE__ || ANDROID
@@ -136,7 +137,7 @@
 #if defined(__sgi)
             pthread_setrunon_np( pd->cpunum );
 #elif defined(HAVE_PTHREAD_SETAFFINITY_NP) || defined(HAVE_THREE_PARAM_SCHED_SETAFFINITY) || defined(HAVE_TWO_PARAM_SCHED_SETAFFINITY)
-            cpu_set_t cpumask;
+            cpuset_t cpumask;
             CPU_ZERO( &cpumask );
             CPU_SET( pd->cpunum, &cpumask );
 
@@ -569,7 +570,7 @@
 
     if (pd->isRunning && Thread::CurrentThread()==this)
     {
-        cpu_set_t cpumask;
+        cpuset_t cpumask;
         CPU_ZERO( &cpumask );
         CPU_SET( pd->cpunum, &cpumask );
 #if defined(HAVE_PTHREAD_SETAFFINITY_NP)
@@ -1031,7 +1032,7 @@
     else
     {
 #if defined(HAVE_PTHREAD_SETAFFINITY_NP) || defined(HAVE_THREE_PARAM_SCHED_SETAFFINITY) || defined(HAVE_TWO_PARAM_SCHED_SETAFFINITY)
-        cpu_set_t cpumask;
+        cpuset_t cpumask;
         CPU_ZERO( &cpumask );
         CPU_SET( cpunum, &cpumask );
 #if defined(HAVE_PTHREAD_SETAFFINITY_NP)
