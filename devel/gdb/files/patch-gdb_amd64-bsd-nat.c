--- gdb/amd64-bsd-nat.c.orig	2021-07-03 10:41:09.000000000 -0700
+++ gdb/amd64-bsd-nat.c	2021-09-16 13:59:34.240785000 -0700
@@ -28,6 +28,7 @@
 #include <sys/types.h>
 #include <sys/ptrace.h>
 #include <machine/reg.h>
+#include <machine/psl.h>
 
 #include "amd64-tdep.h"
 #include "amd64-nat.h"
@@ -142,12 +143,19 @@ amd64bsd_store_inferior_registers (struct regcache *re
   if (regnum == -1 || amd64_native_gregset_supplies_p (gdbarch, regnum))
     {
       struct reg regs;
+      register_t old_rflags;
 
       if (gdb_ptrace (PT_GETREGS, ptid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
 	perror_with_name (_("Couldn't get registers"));
 
+      old_rflags = regs.r_rflags;
       amd64_collect_native_gregset (regcache, &regs, regnum);
 
+      /* This is a workaround about the PSL_USERCHANGE posix limitation. */
+      if ((regs.r_rflags ^ old_rflags ) & ~PSL_USERCHANGE)
+	{
+	  regs.r_rflags ^= (regs.r_rflags ^ old_rflags ) & ~PSL_USERCHANGE;
+	}
       if (gdb_ptrace (PT_SETREGS, ptid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
 	perror_with_name (_("Couldn't write registers"));
 
