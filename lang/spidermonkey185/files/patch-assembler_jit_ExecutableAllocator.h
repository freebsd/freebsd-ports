--- assembler/jit/ExecutableAllocator.h.orig	2016-09-07 UTC
+++ assembler/jit/ExecutableAllocator.h
@@ -391,6 +391,11 @@ public:
     {
         CacheRangeFlush(code, size, CACHE_SYNC_ALL);
     }
+#elif WTF_CPU_ARM_TRADITIONAL && WTF_PLATFORM_FREEBSD
+    static void cacheFlush(void* code, size_t size)
+    {
+	__clear_cache(code, reinterpret_cast<char*>(code) + size);
+    }
 #else
     #error "The cacheFlush support is missing on this platform."
 #endif
