--- volk/tmpl/volk_cpu.tmpl.c.orig	2015-07-09 02:00:33 UTC
+++ volk/tmpl/volk_cpu.tmpl.c
@@ -34,7 +34,35 @@ struct VOLK_CPU volk_cpu;
 
 //implement get cpuid for gcc compilers using a system or local copy of cpuid.h
 #if defined(__GNUC__)
-    #include <cpuid.h>
+    #if defined(HAVE_CPUID_H)
+        #include <cpuid.h>
+    #else
+	#ifdef __FreeBSD__
+#if __i386__
+#define __cpuid(__level, __eax, __ebx, __ecx, __edx) \
+    __asm("cpuid" : "=a"(__eax), "=b" (__ebx), "=c"(__ecx), "=d"(__edx) \
+                  : "0"(__level))
+#else
+/* x86-64 uses %rbx as the base register, so preserve it. */
+#define __cpuid(__level, __eax, __ebx, __ecx, __edx) \
+    __asm("  xchgq  %%rbx,%q1\n" \
+          "  cpuid\n" \
+          "  xchgq  %%rbx,%q1" \
+        : "=a"(__eax), "=r" (__ebx), "=c"(__ecx), "=d"(__edx) \
+        : "0"(__level))
+
+#endif
+
+static __inline int __get_cpuid (unsigned int __level, unsigned int *__eax,
+                                 unsigned int *__ebx, unsigned int *__ecx,
+                                 unsigned int *__edx) {
+    __cpuid(__level, *__eax, *__ebx, *__ecx, *__edx);
+    return 1;
+}
+	#else
+	        #include "gcc_x86_cpuid.h"
+	#endif
+    #endif
     #define cpuid_x86(op, r) __get_cpuid(op, (unsigned int *)r+0, (unsigned int *)r+1, (unsigned int *)r+2, (unsigned int *)r+3)
 
     /* Return Intel AVX extended CPU capabilities register.
