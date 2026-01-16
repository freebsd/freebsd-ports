--- thirdparty/OGDF/src/ogdf/basic/System.cpp.orig	2025-03-31 21:30:23 UTC
+++ thirdparty/OGDF/src/ogdf/basic/System.cpp
@@ -56,6 +56,13 @@
 #    include <mach/vm_statistics.h>
 #    include <mach/mach.h>
 #    include <mach/machine.h>
+#elif defined(__FreeBSD__)
+#    include <stdlib.h>
+#    include <unistd.h>
+#    include <sys/types.h>
+#    include <sys/sysctl.h>
+#    include <sys/time.h>
+#    include <sys/resource.h>
 #elif defined(OGDF_SYSTEM_UNIX)
 #    include <malloc.h>
 #endif
@@ -293,6 +300,39 @@ size_t System::memoryUsedByProcess() {
 	return 0;
 }
 
+#elif defined(__FreeBSD__)
+
+long long System::physicalMemory()
+{
+       unsigned long value;
+       size_t  size = sizeof( value );
+       if (sysctlbyname("hw.physmem", (void *)&value, &size, NULL, 0) != -1)
+               return value;
+       else
+               return 0;
+}
+
+long long System::availablePhysicalMemory()
+{
+       int pageSize = getpagesize ();
+       unsigned long result;
+    size_t size = sizeof (result);
+
+       if (sysctlbyname("vm.stats.vm.v_free_count", (void *)&result, &size, NULL, 0) != -1)
+        return result * pageSize;
+    else
+        return 0;
+}
+
+size_t System::memoryUsedByProcess()
+{
+    struct rusage r;
+    if (getrusage(RUSAGE_SELF, &r) != -1)
+        return r.ru_maxrss;
+    else
+        return 0;
+}
+
 #else
 // LINUX, NOT MAC OS
 long long System::physicalMemory() {
@@ -365,6 +405,19 @@ size_t System::memoryInFreelistOfMalloc() { return mst
 size_t System::memoryAllocatedByMalloc() { return mstats().bytes_used; }
 
 size_t System::memoryInFreelistOfMalloc() { return mstats().bytes_free; }
+
+#elif defined(__FreeBSD__)
+
+size_t System::memoryAllocatedByMalloc()
+{
+       return 0;
+}
+
+size_t System::memoryInFreelistOfMalloc()
+{
+       return 0;
+}
+
 #else
 
 size_t System::memoryAllocatedByMalloc() {
