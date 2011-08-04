--- thirdparty/OGDF/src/basic/System.cpp.orig	2011-08-02 14:18:48.000000000 +0200
+++ thirdparty/OGDF/src/basic/System.cpp	2011-08-02 14:41:15.000000000 +0200
@@ -61,6 +61,12 @@
 #include <mach/vm_statistics.h>
 #include <mach/mach.h>
 #include <mach/machine.h>
+#elif defined(__FreeBSD__)
+#include <stdlib.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#include <libutil.h>
 #elif defined(OGDF_SYSTEM_UNIX)
 #include <malloc.h>
 #endif
@@ -317,6 +323,47 @@
 	return 0;
 }
 
+
+#elif __FreeBSD__
+
+long long System::physicalMemory()
+{
+	unsigned long long value;
+	size_t  size = sizeof( value );
+	if (sysctlbyname("hw.physmem", &value, &size, NULL, 0) !=-1)
+		return value;
+	else 
+		return 0;
+}
+
+long long System::availablePhysicalMemory()
+{
+	unsigned long long pageSize, freePages, inactPages;
+	long long result;
+	size_t  size = sizeof( pageSize );
+	sysctlbyname("hw.pagesize", &pageSize, &size, NULL, 0);
+	sysctlbyname("vm.stats.vm.v_free_count", &freePages, &size, NULL, 0);
+	sysctlbyname("vm.stats.vm.v_inactive_count", &inactPages, &size, NULL, 0);
+	
+	result = (unsigned long long)(freePages + inactPages) * pageSize;
+	return result;
+}
+
+
+size_t System::memoryUsedByProcess()
+{
+#if __FreeBSD_version >= 900035
+	int pid = getpid();
+	struct kinfo_proc *kp;
+
+	if ((kp = kinfo_getproc(pid))) {
+		return (kp->ki_size);
+	}
+#endif
+
+	return 0;
+}
+
 #else
 // LINUX, NOT MAC OS
 long long System::physicalMemory()
@@ -403,6 +450,19 @@
 {
 	return mstats().chunks_free;
 }
+
+#elif __FreeBSD__
+
+size_t System::memoryAllocatedByMalloc()
+{
+	return 0;
+}
+
+size_t System::memoryInFreelistOfMalloc()
+{
+	return 0;
+}
+
 #else
 
 size_t System::memoryAllocatedByMalloc()
