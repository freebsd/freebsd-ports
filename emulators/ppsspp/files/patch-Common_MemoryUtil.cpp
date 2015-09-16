--- Common/MemoryUtil.cpp.orig	2015-02-26 20:05:06 UTC
+++ Common/MemoryUtil.cpp
@@ -49,6 +49,13 @@ static SYSTEM_INFO sys_info;
 #define round_page(x) ((((uintptr_t)(x)) + PAGE_MASK) & ~(PAGE_MASK))
 #endif
 
+#if defined(__FreeBSD__)
+/* setrlimit(2) */
+#include <sys/types.h>
+#include <sys/time.h>
+#include <sys/resource.h>
+#endif
+
 #ifdef __SYMBIAN32__
 #include <e32std.h>
 #define CODECHUNK_SIZE 1024*1024*20
@@ -142,6 +149,21 @@ void* AllocateExecutableMemory(size_t si
 			map_hint = (char*)round_page(&hint_location) - 0x20000000; // 0.5gb lower than our approximate location
 		else
 			map_hint = (char*)0x20000000; // 0.5GB mark in memory
+
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
 	}
 	else if (exec && (uintptr_t) map_hint > 0xFFFFFFFFULL)
 	{
@@ -160,7 +182,7 @@ void* AllocateExecutableMemory(size_t si
 	// printf("Mapped executable memory at %p (size %ld)\n", ptr,
 	//	(unsigned long)size);
 
-#if defined(__FreeBSD__)
+#if !defined(_WIN32) && !defined(__SYMBIAN32__)
 	if (ptr == MAP_FAILED)
 	{
 		ptr = NULL;
