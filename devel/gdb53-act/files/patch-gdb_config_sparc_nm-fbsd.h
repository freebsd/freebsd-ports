--- gdb/config/sparc/nm-fbsd.h.orig	Fri Mar  1 18:35:24 2002
+++ gdb/config/sparc/nm-fbsd.h	Tue Oct 22 16:33:14 2002
@@ -32,36 +32,45 @@
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
+#define REG32_OFFSET_GLOBAL	(0)
+#define REG32_OFFSET_OUT	(32)
+#define REG32_OFFSET_NPC	(96)
+#define REG32_OFFSET_PC		(100)
+#define REG32_OFFSET_PSR	(104)
+#define REG32_OFFSET_Y		(112)
+#define REG32_SIZE		(128)
+#define FPREG32_SIZE		(136)
+
+#define REG64_OFFSET_GLOBAL	(0)
+#define REG64_OFFSET_OUT	(64)
+#define REG64_OFFSET_NPC	(192)
+#define REG64_OFFSET_PC		(200)
+#define REG64_OFFSET_TSTATE	(208)
+#define REG64_OFFSET_Y		(224)
+#define REG64_SIZE		(256)
+#define FPREG64_SIZE		(272)
+
+#define	JB32_OFFSET_PC		REG32_OFFSET_PC
+#define	JB64_OFFSET_PC		REG64_OFFSET_PC
 
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
+#define	reg64	reg
+#define	fpreg64	fpreg
 
 #endif /* NM_FBSD_H */
