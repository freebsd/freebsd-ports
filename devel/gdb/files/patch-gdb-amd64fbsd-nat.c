--- gdb/amd64fbsd-nat.c.orig	2010-02-03 15:30:25.000000000 +0000
+++ gdb/amd64fbsd-nat.c	2011-09-23 03:08:51.942111416 +0100
@@ -27,6 +27,7 @@
 #include <signal.h>
 #include <stddef.h>
 #include <sys/types.h>
+#include <sys/procfs.h>
 #include <sys/ptrace.h>
 #include <sys/sysctl.h>
 #include <machine/reg.h>
@@ -34,6 +35,8 @@
 #include "fbsd-nat.h"
 #include "amd64-tdep.h"
 #include "amd64-nat.h"
+#include "amd64bsd-nat.h"
+#include "i386-nat.h"
 
 
 /* Offset in `struct reg' where MEMBER is stored.  */
@@ -92,6 +95,47 @@
 };
 
 
+/* Transfering the registers between GDB, inferiors and core files.  */
+
+/* Fill GDB's register array with the general-purpose register values
+   in *GREGSETP.  */
+
+void
+supply_gregset (struct regcache *regcache, const gregset_t *gregsetp)
+{
+  amd64_supply_native_gregset (regcache, gregsetp, -1);
+}
+
+/* Fill register REGNUM (if it is a general-purpose register) in
+   *GREGSETPS with the value in GDB's register array.  If REGNUM is -1,
+   do this for all registers.  */
+
+void
+fill_gregset (struct regcache *regcache, gregset_t *gregsetp, int regnum)
+{
+  amd64_collect_native_gregset (regcache, gregsetp, regnum);
+}
+
+/* Fill GDB's register array with the floating-point register values
+   in *FPREGSETP.  */
+
+void
+supply_fpregset (struct regcache *regcache, const fpregset_t *fpregsetp)
+{
+  amd64_supply_fxsave (regcache, -1, fpregsetp);
+}
+
+/* Fill register REGNUM (if it is a floating-point register) in
+   *FPREGSETP with the value in GDB's register array.  If REGNUM is -1,
+   do this for all registers.  */
+
+void
+fill_fpregset (struct regcache *regcache, fpregset_t *fpregsetp, int regnum)
+{
+  amd64_collect_fxsave (regcache, regnum, fpregsetp);
+}
+
+
 /* Support for debugging kernel virtual memory images.  */
 
 #include <sys/types.h>
@@ -155,6 +199,19 @@
 
   /* Add some extra features to the common *BSD/i386 target.  */
   t = amd64bsd_target ();
+
+#ifdef HAVE_PT_GETDBREGS
+
+  i386_use_watchpoints (t);
+
+  i386_dr_low.set_control = amd64bsd_dr_set_control;
+  i386_dr_low.set_addr = amd64bsd_dr_set_addr;
+  i386_dr_low.reset_addr = amd64bsd_dr_reset_addr;
+  i386_dr_low.get_status = amd64bsd_dr_get_status;
+  i386_set_debug_register_length (8);
+
+#endif /* HAVE_PT_GETDBREGS */
+
   t->to_pid_to_exec_file = fbsd_pid_to_exec_file;
   t->to_find_memory_regions = fbsd_find_memory_regions;
   t->to_make_corefile_notes = fbsd_make_corefile_notes;
