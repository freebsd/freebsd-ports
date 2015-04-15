--- Platform.cpp	2015-03-30 17:26:46.000000000 -0400
+++ Platform.cpp.new	2015-03-30 17:26:56.000000000 -0400
@@ -19,6 +19,38 @@
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
