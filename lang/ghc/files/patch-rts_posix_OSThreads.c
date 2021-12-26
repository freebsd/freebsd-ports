--- rts/posix/OSThreads.c.orig	2021-10-28 20:41:34 UTC
+++ rts/posix/OSThreads.c
@@ -325,7 +325,7 @@ getNumberOfProcessors (void)
                     nproc = 1;
             }
         }
-#elif defined(freebsd_HOST_OS)
+#elif defined(freebsd_HOST_OS) && !defined(HAVE_SCHED_GETAFFINITY)
         cpuset_t mask;
         CPU_ZERO(&mask);
         if(cpuset_getaffinity(CPU_LEVEL_CPUSET, CPU_WHICH_PID, -1, sizeof(mask), &mask) == 0) {
