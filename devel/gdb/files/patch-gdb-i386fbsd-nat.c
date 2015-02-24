--- gdb/i386fbsd-nat.c.orig	2012-05-24 18:39:09.000000000 +0200
+++ gdb/i386fbsd-nat.c	2012-08-29 17:19:57.000000000 +0200
@@ -21,10 +21,12 @@
 #include "inferior.h"
 #include "regcache.h"
 #include "target.h"
 
 #include <sys/types.h>
+#include <sys/procfs.h>
 #include <sys/ptrace.h>
 #include <sys/sysctl.h>
+#include <sys/user.h>
 
 #include "fbsd-nat.h"
 #include "i386-tdep.h"
@@ -140,7 +141,6 @@
 #endif /* HAVE_PT_GETDBREGS */
 
 
-  t->to_resume = i386fbsd_resume;
   t->to_pid_to_exec_file = fbsd_pid_to_exec_file;
   t->to_find_memory_regions = fbsd_find_memory_regions;
   t->to_make_corefile_notes = fbsd_make_corefile_notes;
@@ -149,13 +149,33 @@ _initialize_i386fbsd_nat (void)
   /* Support debugging kernel virtual memory images.  */
   bsd_kvm_add_target (i386fbsd_supply_pcb);
 
+#ifdef KERN_PROC_SIGTRAMP
+  /* FreeBSD provides a kern.proc.sigtramp sysctl that we can use to
+     locate the sigtramp.  That way we can still recognize a sigtramp
+     if its location is changed in a new kernel. */
+  {
+    int mib[4];
+    struct kinfo_sigtramp kst;
+    size_t len;
+
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC;
+    mib[2] = KERN_PROC_SIGTRAMP;
+    mib[3] = getpid();
+    len = sizeof (kst);
+    if (sysctl (mib, sizeof(mib)/sizeof(mib[0]), &kst, &len, NULL, 0) == 0)
+      {
+	i386fbsd_sigtramp_start_addr = (uintptr_t)kst.ksigtramp_start;
+	i386fbsd_sigtramp_end_addr = (uintptr_t)kst.ksigtramp_end;
+      }
+  }
+#elif defined(KERN_PS_STRINGS)
   /* FreeBSD provides a kern.ps_strings sysctl that we can use to
      locate the sigtramp.  That way we can still recognize a sigtramp
      if its location is changed in a new kernel.  Of course this is
      still based on the assumption that the sigtramp is placed
      directly under the location where the program arguments and
      environment can be found.  */
-#ifdef KERN_PS_STRINGS
   {
     int mib[2];
     u_long ps_strings;
