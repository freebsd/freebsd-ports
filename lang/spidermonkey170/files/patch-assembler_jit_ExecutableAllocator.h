--- assembler/jit/ExecutableAllocator.h.orig	2013-02-11 15:33:22.000000000 -0700
+++ assembler/jit/ExecutableAllocator.h	2015-08-26 11:42:27.133593000 -0600
@@ -468,6 +468,11 @@
     {
         sync_instruction_memory((caddr_t)code, size);
     }
+#elif WTF_CPU_ARM_TRADITIONAL && WTF_OS_FREEBSD
+    static void cacheFlush(void* code, size_t size)
+    {
+	__clear_cache(code, reinterpret_cast<char*>(code) + size);
+    }
 #endif
 
 private:
