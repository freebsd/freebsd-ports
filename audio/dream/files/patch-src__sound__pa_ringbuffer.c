--- src/sound/pa_ringbuffer.c.orig	2013-11-11 16:33:41 UTC
+++ src/sound/pa_ringbuffer.c
@@ -72,12 +72,13 @@
  ****************/
 
 #if defined(__APPLE__) || defined(__FreeBSD__)
-#   include <libkern/OSAtomic.h>
+#   include <sys/types.h>
+#   include <machine/atomic.h>
 /* Here are the memory barrier functions. Mac OS X and FreeBSD only provide
    full memory barriers, so the three types of barriers are the same. */
-#   define PaUtil_FullMemoryBarrier()  OSMemoryBarrier()
-#   define PaUtil_ReadMemoryBarrier()  OSMemoryBarrier()
-#   define PaUtil_WriteMemoryBarrier() OSMemoryBarrier()
+#   define PaUtil_FullMemoryBarrier()  mb()
+#   define PaUtil_ReadMemoryBarrier()  rmb()
+#   define PaUtil_WriteMemoryBarrier() wmb()
 #elif defined(__GNUC__)
 /* GCC understands volatile asm and "memory" to mean it
  * should not reorder memory read/writes */
