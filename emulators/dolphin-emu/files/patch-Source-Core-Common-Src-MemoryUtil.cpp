--- Source/Core/Common/Src/MemoryUtil.cpp.orig	2012-09-20 13:12:50.000000000 +0200
+++ Source/Core/Common/Src/MemoryUtil.cpp	2012-09-20 13:12:43.000000000 +0200
@@ -33,6 +33,13 @@
 #define round_page(x) ((((unsigned long)(x)) + PAGE_MASK) & ~(PAGE_MASK))
 #endif
 
+#if defined(__FreeBSD__)
+/* setrlimit(2) */
+#include <sys/types.h>
+#include <sys/time.h>
+#include <sys/resource.h>
+#endif
+
 // This is purposely not a full wrapper for virtualalloc/mmap, but it
 // provides exactly the primitive operations that Dolphin needs.
 
@@ -50,7 +57,23 @@
 	// effect of discarding already mapped pages that happen to be in the
 	// requested virtual memory range (such as the emulated RAM, sometimes).
 	if (low && (!map_hint))
+	{
 		map_hint = (char*)round_page(512*1024*1024); /* 0.5 GB rounded up to the next page */
+#if defined(__FreeBSD__)
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
+	}
 #endif
 	void* ptr = mmap(map_hint, size, PROT_READ | PROT_WRITE | PROT_EXEC,
 		MAP_ANON | MAP_PRIVATE
