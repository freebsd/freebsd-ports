--- assembler/jit/ExecutableAllocator.h.orig	2013-10-29 20:40:26 UTC
+++ assembler/jit/ExecutableAllocator.h
@@ -477,6 +477,11 @@ public:
     {
         sync_instruction_memory((caddr_t)code, size);
     }
+#elif CPU(ARM_TRADITIONAL) && OS(FREEBSD) && COMPILER(CLANG)
+    static void cacheFlush(void* code, size_t size)
+    {
+	__clear_cache(code, reinterpret_cast<char*>(code) + size);
+    }
 #endif
 
 private:
