FreeBSD ignores address hints with default RLIMIT_DATA

--- Utilities/JIT.cpp.orig	2017-07-20 15:05:34 UTC
+++ Utilities/JIT.cpp
@@ -30,6 +30,8 @@
 
 #ifdef _WIN32
 #include <Windows.h>
+#else
+#include <sys/mman.h>
 #endif
 
 #include "JIT.h"
@@ -47,6 +49,11 @@ static void* const s_memory = []() -> void*
 	llvm::InitializeNativeTargetAsmPrinter();
 	LLVMLinkInMCJIT();
 
+#ifdef MAP_32BIT
+	auto ptr = ::mmap(nullptr, s_memory_size, PROT_NONE, MAP_ANON | MAP_PRIVATE | MAP_32BIT, -1, 0);
+	if (ptr != MAP_FAILED)
+		return ptr;
+#else
 	for (u64 addr = 0x10000000; addr <= 0x80000000 - s_memory_size; addr += 0x1000000)
 	{
 		if (auto ptr = utils::memory_reserve(s_memory_size, (void*)addr))
@@ -54,6 +61,7 @@ static void* const s_memory = []() -> void*
 			return ptr;
 		}
 	}
+#endif
 
 	return utils::memory_reserve(s_memory_size);
 }();
