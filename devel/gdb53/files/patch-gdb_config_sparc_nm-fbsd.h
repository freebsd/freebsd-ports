--- gdb/config/sparc/nm-fbsd.h	Fri Mar  1 18:35:24 2002
+++ gdb/config/sparc/nm-fbsd.h	Tue Oct 15 18:53:19 2002
@@ -36,6 +36,7 @@
 
 #define SVR4_SHARED_LIBS
 
+#include "config/nm-fbsd.h"
 #include "solib.h"		/* Support for shared libraries. */
 #include "elf/common.h"		/* Additional ELF shared library info. */
 
@@ -49,12 +50,9 @@
 #define GDB_GREGSET_T	struct reg
 #define GDB_FPREGSET_T	struct fpreg
 
-#define regs		trapframe
-#define r_g1		tf_global[1]
-#define r_ps		tf_tstate
-#define r_pc		tf_tpc
-#define r_npc		tf_tnpc
-#define r_y		tf_y
+#define regs		reg
+#define r_g1		r_global[1]
+#define r_ps		r_tstate
 
 #define FPU_FSR_TYPE	unsigned long
 #define fp_status	fpreg		/* our reg.h */
