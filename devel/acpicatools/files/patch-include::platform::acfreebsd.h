--- acpica-unix-20030523/include/platform/acfreebsd.h.orig	Sat May 24 09:10:56 2003
+++ acpica-unix-20030523/include/platform/acfreebsd.h	Fri Jun 13 00:17:53 2003
@@ -126,7 +126,25 @@
 /* FreeBSD uses GCC */
 
 #include "acgcc.h"
+#if 0
 #include <machine/acpica_machdep.h>
+#endif
+
+#ifdef _KERNEL
+#include "opt_acpi.h"
+#endif
+
+#ifdef ACPI_DEBUG
+#define ACPI_DEBUG_OUTPUT	/* for backward compatibility */
+#endif
+
+#ifdef _KERNEL
+#include "opt_acpi.h"
+#endif
+
+#ifdef ACPI_DEBUG
+#define ACPI_DEBUG_OUTPUT	/* for backward compatibility */
+#endif
 
 #ifdef _KERNEL
 #include <sys/ctype.h>
@@ -135,15 +153,11 @@
 #include <sys/libkern.h>
 #include <machine/stdarg.h>
 
-#define asm         __asm
-#define __cli()     disable_intr()
-#define __sti()     enable_intr()
-
-#ifdef ACPI_DEBUG_OUTPUT
 #ifdef DEBUGGER_THREADING
 #undef DEBUGGER_THREADING
 #endif /* DEBUGGER_THREADING */
 #define DEBUGGER_THREADING 0    /* integrated with DDB */
+#ifdef ACPI_DEBUG_OUTPUT
 #include "opt_ddb.h"
 #ifdef DDB
 #define ACPI_DEBUGGER
@@ -157,6 +171,7 @@
 
 #define __cli()
 #define __sti()
+#define ACPI_FLUSH_CPU_CACHE()
 
 #endif /* _KERNEL */
 
@@ -196,5 +211,16 @@
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
