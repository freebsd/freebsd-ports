--- tbprobe.c.orig	2026-10-20 01:13:44 UTC
+++ tbprobe.c
@@ -108,7 +108,11 @@
 #define board(s)                ((uint64_t)1 << (s))
 static inline unsigned _lsb(uint64_t b) {
   size_t idx;
+#if defined(__x86_64__)
 __asm__("bsfq %1, %0": "=r"(idx):"rm"(b));
+#else
+  idx = __builtin_ctzll(b);
+#endif
   return idx;
 }
 
