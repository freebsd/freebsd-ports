--- gdb/amd64fbsd-nat.c.orig	2010-10-13 14:53:14.425152000 -0400
+++ gdb/amd64fbsd-nat.c	2010-10-13 15:15:01.080198000 -0400
@@ -27,6 +27,7 @@
 #include <signal.h>
 #include <stddef.h>
 #include <sys/types.h>
+#include <sys/procfs.h>
 #include <sys/ptrace.h>
 #include <sys/sysctl.h>
 #include <machine/reg.h>
@@ -92,6 +93,47 @@
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
