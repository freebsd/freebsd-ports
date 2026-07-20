--- myutils.cpp.orig	2022-01-13 23:29:59 UTC
+++ myutils.cpp
@@ -1050,7 +1050,62 @@
 		g_PeakMemUseBytes = Bytes;
 	return Bytes;
 	}
+#elif defined(__FreeBSD__)
+
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#include <unistd.h>
 
+double GetMemUseBytes()
+	{
+	static int initialized = 0;
+	static int mib[4];
+	static size_t len;
+
+	if (!initialized)
+	{
+		mib[0] = CTL_KERN;
+		mib[1] = KERN_PROC;
+		mib[2] = KERN_PROC_PID;
+		mib[3] = getpid();
+		len = sizeof(struct kinfo_proc);
+		initialized = 1;
+	}
+
+	struct kinfo_proc kp;
+	if (sysctl(mib, 4, &kp, &len, NULL, 0) == -1)
+		return 0.0;
+
+	// Resident set size in pages → convert to bytes
+	long page_size = getpagesize();
+	double bytes = (double)kp.ki_rssize * page_size;
+
+	if (bytes > g_PeakMemUseBytes)
+		g_PeakMemUseBytes = bytes;
+
+	return bytes;
+
+	}
+
+double GetPhysMemBytes()
+	{
+ 	#if BITS == 32
+	unsigned int physmem32 = 0;
+	#else
+	uint64_t physmem = 0;
+	#endif
+
+	size_t len = sizeof(physmem);
+
+	static int mib[2] = { CTL_HW, HW_PHYSMEM };
+	if (sysctl(mib, 2, &physmem, &len, NULL, 0) == -1)
+		return 0.0;
+
+	return (double)physmem;
+
+	}
+
 #elif defined(__MACH__)
 #include <memory.h>
 #include <stdlib.h>
