--- Platform.cpp.orig	2014-04-22 21:40:50 UTC
+++ Platform.cpp
@@ -19,6 +19,38 @@ void SetAffinity ( int cpu )
   SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);
 }
 
+#elif __FreeBSD__
+
+#include <string.h>
+#include <errno.h>
+#include <sys/types.h>
+#include <sys/param.h>
+#include <sys/cpuset.h>
+
+void
+SetAffinity(int cpu)
+{
+    cpuset_t mask;
+    unsigned int i;
+
+    fprintf(stdout, "SetAffinity called with arg %d\n", cpu);
+
+    CPU_ZERO(&mask);
+    i = 0;
+    do {
+        if (cpu & 1) {
+            CPU_SET(i, &mask);
+        }
+        i++;
+        cpu >>= 1;
+    } while (cpu);
+
+    if (cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID, -1, sizeof(cpuset_t), &mask) == -1)
+    {
+        fprintf(stderr, "SetAffinity() failed.  %s", strerror(errno));
+    }
+}
+
 #else
 
 #include <sched.h>
