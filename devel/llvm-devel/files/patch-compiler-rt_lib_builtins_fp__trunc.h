--- compiler-rt/lib/builtins/fp_trunc.h.orig
+++ compiler-rt/lib/builtins/fp_trunc.h
@@ -93,7 +93,7 @@
 static const int dstExpBits = 8;
 
 #elif defined DST_HALF
-#ifdef COMPILER_RT_HAS_FLOAT16
+#if defined(COMPILER_RT_HAS_FLOAT16) && !defined(__i386__)
 typedef _Float16 dst_t;
 #else
 typedef uint16_t dst_t;
