--- Utilities/JIT.cpp.orig	2017-07-10 15:42:02 UTC
+++ Utilities/JIT.cpp
@@ -31,6 +31,10 @@
 #include <Windows.h>
 #endif
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#include <sys/resource.h>
+#endif
+
 #include "JIT.h"
 
 // Memory manager mutex
@@ -45,6 +49,21 @@ static void* const s_memory = []() -> void*
 	llvm::InitializeNativeTarget();
 	llvm::InitializeNativeTargetAsmPrinter();
 	LLVMLinkInMCJIT();
+
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+	// XXX Fix maximum data segment size (data + BSS + heap) to 256 MB.
+	// This allows avoiding calling mmap(2) with MAP_FIXED.
+	// On FreeBSD, without lowering this limit, calling mmap(2)
+	// without MAP_FIXED will result in getting an address just
+	// beyond maximum data segment size which will be far beyond
+	// the desired 2 GB.
+	struct rlimit limit;
+	limit.rlim_cur = 0x10000000; // 256 MB
+	limit.rlim_max = 0x10000000;
+	if(setrlimit(RLIMIT_DATA, &limit) != 0) {
+		LOG_ERROR(GENERAL, "LLVM: Failed to lower maximum data segment size");
+	}
+#endif
 
 	for (u64 addr = 0x10000000; addr <= 0x80000000 - s_memory_size; addr += 0x1000000)
 	{
