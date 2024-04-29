--- util/cpuinfo-ppc.c.orig	2024-01-29 19:13:22 UTC
+++ util/cpuinfo-ppc.c
@@ -6,13 +6,21 @@
 #include "qemu/osdep.h"
 #include "host/cpuinfo.h"
 
-#include <asm/cputable.h>
 #ifdef CONFIG_GETAUXVAL
 # include <sys/auxv.h>
 #else
+# ifdef __linux__
+#  include <asm/cputable.h>
+# elif defined(__FreeBSD__)
+#  include <machine/cpu.h>
+# endif
 # include "elf.h"
 #endif
 
+#ifndef PPC_FEATURE2_ARCH_3_1
+# define PPC_FEATURE2_ARCH_3_1       0x00040000
+#endif
+
 unsigned cpuinfo;
 
 /* Called both as constructor and (possibly) via other constructors. */
@@ -53,7 +61,7 @@ unsigned __attribute__((constructor)) cpuinfo_init(voi
              * always have both anyway, since VSX came with Power7
              * and crypto came with Power8.
              */
-            if (hwcap2 & PPC_FEATURE2_VEC_CRYPTO) {
+            if (hwcap2 & PPC_FEATURE2_HAS_VEC_CRYPTO) {
                 info |= CPUINFO_CRYPTO;
             }
         }
