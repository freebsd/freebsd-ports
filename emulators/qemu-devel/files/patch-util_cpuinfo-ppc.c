--- util/cpuinfo-ppc.c.orig	2023-08-29 11:28:39 UTC
+++ util/cpuinfo-ppc.c
@@ -9,8 +9,14 @@
 #ifdef CONFIG_GETAUXVAL
 # include <sys/auxv.h>
 #else
-# include <asm/cputable.h>
+# ifdef __linux__
+#  include <asm/cputable.h>
+# endif
 # include "elf.h"
+#endif
+
+#ifndef PPC_FEATURE2_ARCH_3_1
+# define PPC_FEATURE2_ARCH_3_1       0x00040000
 #endif
 
 unsigned cpuinfo;
