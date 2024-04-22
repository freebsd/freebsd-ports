--- util/cpuinfo-ppc.c.orig	2024-01-26 18:16:35 UTC
+++ util/cpuinfo-ppc.c
@@ -6,11 +6,17 @@
 #include "qemu/osdep.h"
 #include "host/cpuinfo.h"
 
-#include <asm/cputable.h>
 #ifdef CONFIG_GETAUXVAL
 # include <sys/auxv.h>
+# ifdef __linux__
+#  include <asm/cputable.h>
+# endif
 #else
 # include "elf.h"
+#endif
+
+#ifndef PPC_FEATURE2_ARCH_3_1
+# define PPC_FEATURE2_ARCH_3_1       0x00040000
 #endif
 
 unsigned cpuinfo;
