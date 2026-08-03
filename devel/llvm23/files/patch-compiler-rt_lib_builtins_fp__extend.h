--- compiler-rt/lib/builtins/fp_extend.h.orig
+++ compiler-rt/lib/builtins/fp_extend.h
@@ -53,7 +53,7 @@
 static const int srcExpBits = 15;
 
 #elif defined SRC_HALF
-#ifdef COMPILER_RT_HAS_FLOAT16
+#if defined(COMPILER_RT_HAS_FLOAT16) && !defined(__i386__)
 typedef _Float16 src_t;
 #else
 typedef uint16_t src_t;
