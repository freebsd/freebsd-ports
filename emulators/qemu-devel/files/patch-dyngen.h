# 1.9
Index: qemu/dyngen.h
@@ -59,7 +59,7 @@
 {
     unsigned long p;
 
-    p = start & ~(MIN_CACHE_LINE_SIZE - 1);
+    start &= ~(MIN_CACHE_LINE_SIZE - 1);
     stop = (stop + MIN_CACHE_LINE_SIZE - 1) & ~(MIN_CACHE_LINE_SIZE - 1);
     
     for (p = start; p < stop; p += MIN_CACHE_LINE_SIZE) {
