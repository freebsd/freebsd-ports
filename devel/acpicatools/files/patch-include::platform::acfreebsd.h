--- include/platform/acfreebsd.h.orig	Mon May 20 23:27:26 2002
+++ include/platform/acfreebsd.h	Sat Jun  1 01:12:11 2002
@@ -156,6 +156,7 @@
 
 #define __cli()
 #define __sti()
+#define ACPI_FLUSH_CPU_CACHE()
 
 #endif /* _KERNEL */
 
@@ -195,5 +196,16 @@
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
