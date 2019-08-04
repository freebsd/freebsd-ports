--- src/Timer.cpp.orig	2019-08-03 00:25:18 UTC
+++ src/Timer.cpp
@@ -35,7 +35,19 @@ double Timer::update_time(void) {
 
 unsigned long long Timer::rdtsc(void) {
   unsigned int hi, lo;
+#ifdef __amd64__
   __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
+#elif __powerpc__
+  unsigned int tmp;
+  __asm__ ("0:"
+            "mftbu %[hi32]\n"
+            "mftb %[lo32]\n"
+            "mftbu %[tmp]\n"
+            "cmpw %[tmp],%[hi32]\n"
+            "bne 0b\n"
+            : [hi32] "=r"(hi), [lo32] "=r"(lo),
+            [tmp] "=r"(tmp));
+#endif
   return ((unsigned long long) lo) | (((unsigned long long) hi)<<32);
 }
 
