--- test/common/memory_usage.h.orig	2025-10-29 11:31:36 UTC
+++ test/common/memory_usage.h
@@ -26,6 +26,13 @@
 #include "utils.h"
 #include "utils_assert.h"
 
+#if __FreeBSD__
+#include <unistd.h>
+#include <sys/types.h>
+#include <sys/user.h>
+#include <libutil.h>
+#endif
+
 #if __unix__ || __sun
 #include <sys/resource.h>
 #include <unistd.h>
@@ -93,6 +100,17 @@ namespace utils {
         bool status = GetProcessMemoryInfo(GetCurrentProcess(), &mem, sizeof(mem)) != 0;
         ASSERT(status, nullptr);
         return stat == currentUsage ? mem.PagefileUsage : mem.PeakPagefileUsage;
+#elif __FreeBSD__
+        /* Inspired from sys/compat/linprocfs/linprocfs.c */
+        long unsigned size = 0;
+        struct kinfo_proc *kip = kinfo_getproc(getpid());
+        ASSERT(kip != nullptr, "Failed to get process info.");
+        size = (long unsigned)kip->ki_size;
+        free (kip);
+        // VmPeak not supported
+        if (stat == peakUsage)
+            ASSERT(size, "VmPeak not supported.");
+        return size;
 #elif __unix__
         long unsigned size = 0;
         FILE* fst = fopen("/proc/self/status", "r");
