--- gdb/amd64bsd-nat.c.orig	2011-09-23 01:35:24.211306143 +0100
+++ gdb/amd64bsd-nat.c	2011-09-23 01:28:28.444487431 +0100
@@ -33,6 +33,7 @@
 
 #include "amd64-tdep.h"
 #include "amd64-nat.h"
+#include "amd64bsd-nat.h"
 #include "inf-ptrace.h"
 
 
@@ -126,3 +127,80 @@
   t->to_store_registers = amd64bsd_store_inferior_registers;
   return t;
 }
+
+
+/* Support for debug registers.  */
+
+#ifdef HAVE_PT_GETDBREGS
+
+/* Not all versions of FreeBSD/i386 that support the debug registers
+   have this macro.  */
+#ifndef DBREG_DRX
+#define DBREG_DRX(d, x) ((&d->dr0)[x])
+#endif
+
+static void
+amd64bsd_dr_set (int regnum, unsigned long value)
+{
+  struct dbreg dbregs;
+
+  if (ptrace (PT_GETDBREGS, PIDGET (inferior_ptid),
+              (PTRACE_TYPE_ARG3) &dbregs, 0) == -1)
+    perror_with_name (_("Couldn't get debug registers"));
+
+  /* For some mysterious reason, some of the reserved bits in the
+     debug control register get set.  Mask these off, otherwise the
+     ptrace call below will fail.  */
+  DBREG_DRX ((&dbregs), 7) &= ~(0x0000fc00);
+
+  DBREG_DRX ((&dbregs), regnum) = value;
+
+  if (ptrace (PT_SETDBREGS, PIDGET (inferior_ptid),
+              (PTRACE_TYPE_ARG3) &dbregs, 0) == -1)
+    perror_with_name (_("Couldn't write debug registers"));
+}
+
+void
+amd64bsd_dr_set_control (unsigned long control)
+{
+  amd64bsd_dr_set (7, control);
+}
+
+void
+amd64bsd_dr_set_addr (int regnum, CORE_ADDR addr)
+{
+  gdb_assert (regnum >= 0 && regnum <= 4);
+
+  amd64bsd_dr_set (regnum, addr);
+}
+
+void
+amd64bsd_dr_reset_addr (int regnum)
+{
+  gdb_assert (regnum >= 0 && regnum <= 4);
+
+  amd64bsd_dr_set (regnum, 0);
+}
+
+unsigned long
+amd64bsd_dr_get_status (void)
+{
+  struct dbreg dbregs;
+
+  /* FIXME: kettenis/2001-03-31: Calling perror_with_name if the
+     ptrace call fails breaks debugging remote targets.  The correct
+     way to fix this is to add the hardware breakpoint and watchpoint
+     stuff to the target vector.  For now, just return zero if the
+     ptrace call fails.  */
+  if (ptrace (PT_GETDBREGS, PIDGET (inferior_ptid),
+	      (PTRACE_TYPE_ARG3) &dbregs, 0) == -1)
+#if 0
+    perror_with_name (_("Couldn't read debug registers"));
+#else
+    return 0;
+#endif
+
+  return DBREG_DRX ((&dbregs), 6);
+}
+
+#endif /* PT_GETDBREGS */
