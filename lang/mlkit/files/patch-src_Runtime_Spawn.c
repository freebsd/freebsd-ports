--- src/Runtime/Spawn.c.orig	2023-03-02 09:01:41 UTC
+++ src/Runtime/Spawn.c
@@ -16,6 +16,8 @@
 // For getting cpu usage of threads
 // #include <mach/mach.h>
 // #include <sys/resource.h>
+#elif defined(__FreeBSD__)
+#include <sys/sysctl.h>
 #elif defined(__linux__)
 #include <sys/sysinfo.h>
 // #include <sys/resource.h>
@@ -503,6 +505,12 @@ numCores(void) {
   }
 #elif defined(__linux__)
   ncores = get_nprocs();
+#elif defined(__FreeBSD__)
+  size_t ncores_size = sizeof(ncores);
+  if (sysctlbyname("hw.ncpu", &ncores, &ncores_size, NULL, 0) != 0) {
+    fprintf(stderr, "sysctlbyname (hw.ncpu) failed.");
+    ncores = -1;
+  }
 #else
   fprintf(stderr, "operating system not recognised\n");
   ncores = -1;
