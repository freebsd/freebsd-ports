https://github.com/hrydgard/ppsspp/pull/9857

--- Common/MemoryUtil.cpp.orig	2017-05-27 09:58:05 UTC
+++ Common/MemoryUtil.cpp
@@ -154,7 +154,7 @@ void *AllocateExecutableMemory(size_t size) {
 	}
 #else
 	static char *map_hint = 0;
-#if defined(_M_X64)
+#if defined(_M_X64) && !defined(MAP_32BIT)
 	// Try to request one that is close to our memory location if we're in high memory.
 	// We use a dummy global variable to give us a good location to start from.
 	if (!map_hint) {
@@ -176,7 +176,7 @@ void *AllocateExecutableMemory(size_t size) {
 	void* ptr = mmap(map_hint, size, prot,
 		MAP_ANON | MAP_PRIVATE
 #if defined(_M_X64) && defined(MAP_32BIT)
-		| ((uintptr_t) map_hint == 0 ? MAP_32BIT : 0)
+		| MAP_32BIT
 #endif
 		, -1, 0);
 
@@ -193,7 +193,7 @@ void *AllocateExecutableMemory(size_t size) {
 		ERROR_LOG(MEMMAP, "Failed to allocate executable memory (%d)", (int)size);
 		PanicAlert("Failed to allocate executable memory\n%s", GetLastErrorMsg());
 	}
-#if defined(_M_X64) && !defined(_WIN32)
+#if defined(_M_X64) && !defined(MAP_32BIT) && !defined(_WIN32)
 	else if ((uintptr_t)map_hint <= 0xFFFFFFFF) {
 		// Round up if we're below 32-bit mark, probably allocating sequentially.
 		map_hint += round_page(size);
