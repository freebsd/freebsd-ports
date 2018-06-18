--- src/3rdparty/masm/assembler/ARM64Assembler.h 2018-02-06 19:49:18 UTC
+++ src/3rdparty/masm/assembler/ARM64Assembler.h
@@ -3032,6 +3032,8 @@
             linuxPageFlush(current, current + page);
 
         linuxPageFlush(current, end);
+#elif OS(FREEBSD)
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(QNX)
 #if !ENABLE(ASSEMBLER_WX_EXCLUSIVE)
         msync(code, size, MS_INVALIDATE_ICACHE);

