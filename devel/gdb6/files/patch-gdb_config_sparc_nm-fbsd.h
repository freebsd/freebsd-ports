--- gdb/config/sparc/nm-fbsd.h.orig	Fri Mar  1 18:35:24 2002
+++ gdb/config/sparc/nm-fbsd.h	Thu Oct 17 06:00:39 2002
@@ -32,36 +32,27 @@
 #define ATTACH_DETACH
 
 
-/* Shared library support.  */
+#include "regcache.h"
+
+/* Get generic FreeBSD native definitions. */
+
+#include "config/nm-fbsd.h"
+
+/* Shared library support. */
 
 #define SVR4_SHARED_LIBS
 
 #include "solib.h"		/* Support for shared libraries. */
 #include "elf/common.h"		/* Additional ELF shared library info. */
 
-/* Make things match up with what is expected in sparc-nat.c.  */
+/* Before storing, we need to read all the registers.  */
+
+#define CHILD_PREPARE_TO_STORE() read_register_bytes (0, NULL, REGISTER_BYTES)
+
+#define	reg32	reg
+#define	reg64	reg
 
-#define PTRACE_GETREGS	 PT_GETREGS
-#define PTRACE_SETREGS	 PT_SETREGS
-#define PTRACE_GETFPREGS PT_GETFPREGS
-#define PTRACE_SETFPREGS PT_SETFPREGS
-
-#define GDB_GREGSET_T	struct reg
-#define GDB_FPREGSET_T	struct fpreg
-
-#define regs		trapframe
-#define r_g1		tf_global[1]
-#define r_ps		tf_tstate
-#define r_pc		tf_tpc
-#define r_npc		tf_tnpc
-#define r_y		tf_y
-
-#define FPU_FSR_TYPE	unsigned long
-#define fp_status	fpreg		/* our reg.h */
-#define fpu		fpreg		/* our reg.h */
-#define fpu_regs	fr_regs		/* one field of fpu_fr on Solaris */
-#define fpu_fr		fr_regs		/* a union w/in struct fpu on Solaris */
-#define fpu_fsr		fr_fsr
-#define Fpu_fsr		fr_fsr
+#define	fpreg32	fpreg
+#define	fpreg64	fpreg
 
 #endif /* NM_FBSD_H */
