--- backends/sparc_initreg.c.orig	2017-06-19 14:45:16 UTC
+++ backends/sparc_initreg.c
@@ -33,7 +33,7 @@
 #include "system.h"
 #include <stdlib.h>
 #ifdef __sparc__
-# include <asm/ptrace.h>
+# include <sys/types.h>
 # include <sys/ptrace.h>
 #endif
 
@@ -50,29 +50,29 @@ EBLHOOK (set_initial_registers_tid) (pid
 #else /* __sparc__ */
 
 
-  /* The pt_regs structure filled in by PTRACE_GETREGS provides the
+  /* The pt_regs structure filled in by PT_GETREGS provides the
      PC, the global registers and the output registers.  Note how the
      %g0 register is not explicitly provided in the structure (it's
      value is always 0) and the resulting weird packing in the u_regs
      array: the last element is not used.  */
   
-  struct pt_regs regs;
-  if (ptrace (PTRACE_GETREGS, tid, &regs, 0) == -1)
+  struct reg regs;
+  if (ptrace (PT_GETREGS, tid, (caddr_t)&regs, 0) == -1)
     return false;
 
   /* PC: no DWARF number  */
-  if (!setfunc (-1, 1, (Dwarf_Word *) &regs.tpc, arg))
+  if (!setfunc (-1, 1, (Dwarf_Word *) &regs.r_tpc, arg))
     return false;
   
   /* Global registers: DWARF 0 .. 7  */
   Dwarf_Word zero = 0;
   if (!setfunc (0, 1, &zero, arg))
     return false;
-  if (!setfunc (1, 7, (Dwarf_Word *) &regs.u_regs[0], arg))
+  if (!setfunc (1, 7, (Dwarf_Word *) &regs.r_global[0], arg))
     return false;
 
   /* Output registers: DWARF  8 .. 15  */
-  if (!setfunc (8, 8, (Dwarf_Word *) &regs.u_regs[7], arg))
+  if (!setfunc (8, 8, (Dwarf_Word *) &regs.r_out[0], arg))
     return false;
 
   /* Local and input registers must be read from the stack.  They are
@@ -80,7 +80,7 @@ EBLHOOK (set_initial_registers_tid) (pid
      read above.  */
 
   Dwarf_Word locals_outs[16];
-  Dwarf_Word sp = regs.u_regs[13];
+  Dwarf_Word sp = regs.r_out[5];
 
   if (sp & 1)
     {
@@ -91,9 +91,9 @@ EBLHOOK (set_initial_registers_tid) (pid
 
       for (unsigned i = 0; i < 16; i++)
         {
-          locals_outs[i] = ptrace (PTRACE_PEEKDATA, tid,
+          locals_outs[i] = ptrace (PT_READ_D, tid,
                                    (void *) (uintptr_t) (sp + (i * 8)),
-                                   NULL);
+                                   0);
           if (errno != 0)
             return false;
         }
@@ -104,9 +104,9 @@ EBLHOOK (set_initial_registers_tid) (pid
 
       for (unsigned i = 0; i < 8; i++)
         {
-          Dwarf_Word tuple = ptrace (PTRACE_PEEKDATA, tid,
+          Dwarf_Word tuple = ptrace (PT_READ_D, tid,
                                      (void *) (uintptr_t) (sp + (i * 8)),
-                                     NULL);
+                                     0);
           if (errno != 0)
             return false;
 
