--- src/core/SkCpu.cpp.orig	2025-01-20 04:43:13 UTC
+++ src/core/SkCpu.cpp
@@ -10,6 +10,17 @@
 #include "include/private/SkOnce.h"
 #include "src/core/SkCpu.h"
 
+#ifdef __FreeBSD__
+#include <sys/auxv.h>
+static unsigned long getauxval(unsigned long aux) {
+    unsigned long val = 0;
+
+    elf_aux_info((int)aux, &val, sizeof aux);
+
+    return val;
+}
+#endif
+
 #if defined(SK_CPU_X86)
     #if defined(_MSC_VER)
         #include <intrin.h>
