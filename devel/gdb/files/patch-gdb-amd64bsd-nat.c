--- gdb/amd64bsd-nat.c.orig	2016-02-10 04:19:39.000000000 +0100
+++ gdb/amd64bsd-nat.c	2016-03-04 11:17:58.581638025 +0100
@@ -28,6 +28,7 @@
 #include <sys/types.h>
 #include <sys/ptrace.h>
 #include <machine/reg.h>
+#include <machine/psl.h>
 
 #include "amd64-tdep.h"
 #include "amd64-nat.h"
@@ -98,14 +99,25 @@
 
   if (regnum == -1 || amd64_native_gregset_supplies_p (gdbarch, regnum))
     {
-      struct reg regs;
+      struct reg regs, oldregs;
 
+      memset( &regs, 0, sizeof(struct reg));
+      memset( &oldregs, 0, sizeof(struct reg));
       if (ptrace (PT_GETREGS, get_ptrace_pid (inferior_ptid),
                   (PTRACE_TYPE_ARG3) &regs, 0) == -1)
         perror_with_name (_("Couldn't get registers"));
 
+      ptrace (PT_GETREGS, get_ptrace_pid (inferior_ptid),
+		  (PTRACE_TYPE_ARG3) &oldregs, 0);
       amd64_collect_native_gregset (regcache, &regs, regnum);
 
+      if( (regs.r_rflags ^ oldregs.r_rflags ) & ~PSL_USERCHANGE)
+        {
+          //printf("regs.r_rflags = 0x%8.8lX\n", regs.r_rflags );
+          //printf("oldregs.r_rflags = 0x%8.8lX\n", oldregs.r_rflags );
+          regs.r_rflags ^= (regs.r_rflags ^ oldregs.r_rflags ) & ~PSL_USERCHANGE;
+          //printf("    allowed regs.r_rflags = 0x%8.8X\n", regs.r_rflags );
+        }
       if (ptrace (PT_SETREGS, get_ptrace_pid (inferior_ptid),
 	          (PTRACE_TYPE_ARG3) &regs, 0) == -1)
         perror_with_name (_("Couldn't write registers"));
