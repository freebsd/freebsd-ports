--- progs/xdemos/glthreads.c.orig	Fri May 18 20:28:57 2007
+++ progs/xdemos/glthreads.c	Fri May 18 20:32:37 2007
@@ -505,7 +505,7 @@
    for (i = 0; i < numThreads; i++) {
       pthread_create(&WinThreads[i].Thread, NULL, thread_function,
                      (void*) &WinThreads[i]);
-      printf("glthreads: Created thread %u\n", (unsigned int) WinThreads[i].Thread);
+      printf("glthreads: Created thread %lu\n", (unsigned long) WinThreads[i].Thread);
    }
 
    if (MultiDisplays)
