--- include/platform/acfreebsd.h.orig	Sat Jul 27 03:19:45 2002
+++ include/platform/acfreebsd.h	Fri Aug  9 20:53:32 2002
@@ -126,7 +126,9 @@
 /* FreeBSD uses GCC */
 
 #include "acgcc.h"
+#if 0
 #include <machine/acpica_machdep.h>
+#endif
 
 #ifdef _KERNEL
 #include <sys/ctype.h>
@@ -157,6 +159,7 @@
 
 #define __cli()
 #define __sti()
+#define ACPI_FLUSH_CPU_CACHE()
 
 #endif /* _KERNEL */
 
@@ -196,5 +199,16 @@
     return ((char *)s);
 }
 #endif /* _KERNEL */
+
+#if defined(__ia64__) || defined(__x86_64__)
+#define ACPI_MACHINE_WIDTH             64
+#define COMPILER_DEPENDENT_INT64       long
+#define COMPILER_DEPENDENT_UINT64      unsigned long
+#else
+#define ACPI_MACHINE_WIDTH             32
+#define COMPILER_DEPENDENT_INT64       long long
+#define COMPILER_DEPENDENT_UINT64      unsigned long long
+#define ACPI_USE_NATIVE_DIVIDE
+#endif
 
 #endif /* __ACFREEBSD_H__ */
