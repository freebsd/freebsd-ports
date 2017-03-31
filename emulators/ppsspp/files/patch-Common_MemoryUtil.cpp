--- Common/MemoryUtil.cpp.orig	2015-11-19 15:07:48 UTC
+++ Common/MemoryUtil.cpp
@@ -32,6 +32,10 @@
 #include <mach/vm_param.h>
 #endif
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#include <sys/resource.h>
+#endif
+
 #ifndef _WIN32
 #include <unistd.h>
 #endif
@@ -149,6 +153,21 @@ void *AllocateExecutableMemory(size_t si
 			map_hint = (char*)round_page(&hint_location) - 0x20000000; // 0.5gb lower than our approximate location
 		else
 			map_hint = (char*)0x20000000; // 0.5GB mark in memory
+
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+		// XXX Fix maximum data segment size (data + BSS + heap) to 256 MB.
+		// This allows avoiding calling mmap(2) with MAP_FIXED.
+		// On FreeBSD, without lowering this limit, calling mmap(2)
+		// without MAP_FIXED will result in getting an address just
+		// beyond maximum data segment size which will be far beyond
+		// the desired 2 GB.
+		struct rlimit limit;
+		limit.rlim_cur = 0x10000000; // 256 MB
+		limit.rlim_max = 0x10000000;
+		if(setrlimit(RLIMIT_DATA, &limit) != 0) {
+		        PanicAlert("Failed to lower maximum data segment size");
+		}
+#endif
 	}
 	else if ((uintptr_t) map_hint > 0xFFFFFFFFULL)
 	{
