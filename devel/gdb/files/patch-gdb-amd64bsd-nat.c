diff --git gdb/amd64bsd-nat.c gdb/amd64bsd-nat.c
index 66d4289..b1d4a0e 100644
--- gdb/amd64bsd-nat.c
+++ gdb/amd64bsd-nat.c
@@ -28,6 +28,7 @@
 #include <sys/types.h>
 #include <sys/ptrace.h>
 #include <machine/reg.h>
+#include <machine/psl.h>
 
 #include "amd64-tdep.h"
 #include "amd64-nat.h"
@@ -98,14 +99,24 @@ amd64bsd_store_inferior_registers (struct target_ops *ops,
 
   if (regnum == -1 || amd64_native_gregset_supplies_p (gdbarch, regnum))
     {
-      struct reg regs;
+      struct reg regs, oldregs;
 
+      memset( &regs, 0, sizeof(struct reg));
+      memset( &oldregs, 0, sizeof(struct reg));
       if (ptrace (PT_GETREGS, ptid_get_pid (inferior_ptid),
                   (PTRACE_TYPE_ARG3) &regs, 0) == -1)
         perror_with_name (_("Couldn't get registers"));
 
+      ptrace (PT_GETREGS, ptid_get_pid (inferior_ptid),
+                  (PTRACE_TYPE_ARG3) &oldregs, 0);
       amd64_collect_native_gregset (regcache, &regs, regnum);
 
+      if( (regs.r_rflags ^ oldregs.r_rflags ) & ~PSL_USERCHANGE) {
+        //printf("regs.r_rflags = 0x%8.8lX\n", regs.r_rflags );
+        //printf("oldregs.r_rflags = 0x%8.8lX\n", oldregs.r_rflags );
+        regs.r_rflags ^= (regs.r_rflags ^ oldregs.r_rflags ) & ~PSL_USERCHANGE;
+        //printf("    allowed regs.r_rflags = 0x%8.8X\n", regs.r_rflags );
+      }
       if (ptrace (PT_SETREGS, ptid_get_pid (inferior_ptid),
 	          (PTRACE_TYPE_ARG3) &regs, 0) == -1)
         perror_with_name (_("Couldn't write registers"));
