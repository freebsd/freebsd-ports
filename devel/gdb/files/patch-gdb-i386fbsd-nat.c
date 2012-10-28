--- gdb/i386fbsd-nat.c.orig	2012-05-24 18:39:09.000000000 +0200
+++ gdb/i386fbsd-nat.c	2012-08-29 17:19:57.000000000 +0200
@@ -21,8 +21,10 @@
 #include "inferior.h"
 #include "regcache.h"
 #include "target.h"
+#include "gregset.h"
 
 #include <sys/types.h>
+#include <sys/procfs.h>
 #include <sys/ptrace.h>
 #include <sys/sysctl.h>
 
@@ -80,6 +82,49 @@
 }
 
 
+/* Transfering the registers between GDB, inferiors and core files.  */
+
+/* Fill GDB's register array with the general-purpose register values
+   in *GREGSETP.  */
+
+void
+supply_gregset (struct regcache *regcache, const gregset_t *gregsetp)
+{
+  i386bsd_supply_gregset (regcache, gregsetp);
+}
+
+/* Fill register REGNUM (if it is a general-purpose register) in
+   *GREGSETPS with the value in GDB's register array.  If REGNUM is -1,
+   do this for all registers.  */
+
+void
+fill_gregset (const struct regcache *regcache, gdb_gregset_t *gregsetp, int regnum)
+{
+  i386bsd_collect_gregset (regcache, gregsetp, regnum);
+}
+
+#include "i387-tdep.h"
+
+/* Fill GDB's register array with the floating-point register values
+   in *FPREGSETP.  */
+
+void
+supply_fpregset (struct regcache *regcache, const fpregset_t *fpregsetp)
+{
+  i387_supply_fsave (regcache, -1, fpregsetp);
+}
+
+/* Fill register REGNUM (if it is a floating-point register) in
+   *FPREGSETP with the value in GDB's register array.  If REGNUM is -1,
+   do this for all registers.  */
+
+void
+fill_fpregset (const struct regcache *regcache, gdb_fpregset_t *fpregsetp, int regnum)
+{
+  i387_collect_fsave (regcache, regnum, fpregsetp);
+}
+
+
 /* Support for debugging kernel virtual memory images.  */
 
 #include <sys/types.h>
@@ -141,7 +186,6 @@
 #endif /* HAVE_PT_GETDBREGS */
 
 
-  t->to_resume = i386fbsd_resume;
   t->to_pid_to_exec_file = fbsd_pid_to_exec_file;
   t->to_find_memory_regions = fbsd_find_memory_regions;
   t->to_make_corefile_notes = fbsd_make_corefile_notes;
