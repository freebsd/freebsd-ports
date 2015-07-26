--- volk/tmpl/volk_cpu.tmpl.c.orig	2015-05-12 09:39:44 UTC
+++ volk/tmpl/volk_cpu.tmpl.c
@@ -36,7 +36,31 @@ struct VOLK_CPU volk_cpu;
     #if defined(HAVE_CPUID_H)
         #include <cpuid.h>
     #else
-        #include "gcc_x86_cpuid.h"
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
     #endif
     #define cpuid_x86(op, r) __get_cpuid(op, (unsigned int *)r+0, (unsigned int *)r+1, (unsigned int *)r+2, (unsigned int *)r+3)
 
