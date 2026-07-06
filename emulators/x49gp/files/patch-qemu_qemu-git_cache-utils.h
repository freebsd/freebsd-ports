--- qemu/qemu-git/cache-utils.h.orig	2014-01-09 18:03:02.000000000 +0000
+++ qemu/qemu-git/cache-utils.h	2014-01-09 18:04:14.000000000 +0000
@@ -2,6 +2,9 @@
 #define QEMU_CACHE_UTILS_H
 
 #if defined(_ARCH_PPC)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+
 struct qemu_cache_conf {
     unsigned long dcache_bsize;
     unsigned long icache_bsize;
@@ -15,9 +18,14 @@
 static inline void flush_icache_range(unsigned long start, unsigned long stop)
 {
     unsigned long p, start1, stop1;
-    unsigned long dsize = qemu_cache_conf.dcache_bsize;
-    unsigned long isize = qemu_cache_conf.icache_bsize;
+    static unsigned long dsize;
 
+    if (dsize == 0) {
+        size_t len = sizeof(dsize);
+        if (sysctlbyname("machdep.cacheline_size", &dsize, &len, NULL, 0) != 0)
+            dsize = 32;
+    }
+
     start1 = start & ~(dsize - 1);
     stop1 = (stop + dsize - 1) & ~(dsize - 1);
     for (p = start1; p < stop1; p += dsize) {
@@ -25,9 +33,7 @@
     }
     asm volatile ("sync" : : : "memory");
 
-    start &= start & ~(isize - 1);
-    stop1 = (stop + isize - 1) & ~(isize - 1);
-    for (p = start1; p < stop1; p += isize) {
+    for (p = start1; p < stop1; p += dsize) {
         asm volatile ("icbi 0,%0" : : "r"(p) : "memory");
     }
     asm volatile ("sync" : : : "memory");
