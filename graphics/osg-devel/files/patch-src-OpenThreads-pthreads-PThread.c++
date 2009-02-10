--- src/OpenThreads/pthreads/PThread.c++.orig	2008-11-05 13:27:49.000000000 +0300
+++ src/OpenThreads/pthreads/PThread.c++	2009-02-04 18:06:28.000000000 +0300
@@ -21,6 +21,7 @@
 #include <sys/types.h>
 #include <unistd.h>
 #include <pthread.h>
+#include <pthread_np.h>
 
 #if defined __linux || defined __sun || defined __APPLE__
 #include <string.h>
@@ -125,7 +126,7 @@
 #if defined(__sgi)
             pthread_setrunon_np( pd->cpunum );
 #elif defined(HAVE_PTHREAD_SETAFFINITY_NP) || defined(HAVE_THREE_PARAM_SCHED_SETAFFINITY) || defined(HAVE_TWO_PARAM_SCHED_SETAFFINITY)
-            cpu_set_t cpumask;
+            cpuset_t cpumask;
             CPU_ZERO( &cpumask );
             CPU_SET( pd->cpunum, &cpumask );
 
@@ -541,7 +542,7 @@
 
     if (pd->isRunning && Thread::CurrentThread()==this)
     {
-        cpu_set_t cpumask;
+        cpuset_t cpumask;
         CPU_ZERO( &cpumask );
         CPU_SET( pd->cpunum, &cpumask );
 #if defined(HAVE_PTHREAD_SETAFFINITY_NP)
@@ -975,7 +976,7 @@
     else
     {
 #if defined(HAVE_PTHREAD_SETAFFINITY_NP) || defined(HAVE_THREE_PARAM_SCHED_SETAFFINITY) || defined(HAVE_TWO_PARAM_SCHED_SETAFFINITY)
-        cpu_set_t cpumask;
+        cpuset_t cpumask;
         CPU_ZERO( &cpumask );
         CPU_SET( cpunum, &cpumask );
 
