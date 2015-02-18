--- gdb/amd64fbsd-nat.c.orig	2014-06-11 18:34:41.000000000 +0200
+++ gdb/amd64fbsd-nat.c	2014-09-24 18:27:50.618458853 +0200
@@ -21,13 +21,16 @@
 #include "inferior.h"
 #include "regcache.h"
 #include "target.h"
 
 #include "gdb_assert.h"
 #include <signal.h>
 #include <stddef.h>
 #include <sys/types.h>
+#include <sys/procfs.h>
 #include <sys/ptrace.h>
 #include <sys/sysctl.h>
+#include <sys/user.h>
+#include <sys/param.h>
 #include <machine/reg.h>
 
 #include "fbsd-nat.h"
@@ -247,6 +291,10 @@
 
   SC_RBP_OFFSET = offset;
 
+// Newer versions of FreeBSD provide a better way to locate the signtramp
+#if ( __FreeBSD_version/100000 < 9 ) \
+	|| ( ( __FreeBSD_version/100000 == 9 ) && ( __FreeBSD_version < 902505 ) ) \
+	|| ( ( __FreeBSD_version/100000 == 10 ) && ( __FreeBSD_version < 1000700 ) )
   /* FreeBSD provides a kern.ps_strings sysctl that we can use to
      locate the sigtramp.  That way we can still recognize a sigtramp
      if its location is changed in a new kernel.  Of course this is
@@ -267,4 +315,25 @@
 	amd64fbsd_sigtramp_end_addr = ps_strings;
       }
   }
+#else
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
+	amd64fbsd_sigtramp_start_addr = kst.ksigtramp_start;
+	amd64fbsd_sigtramp_end_addr = kst.ksigtramp_end;
+      }
+  }
+#endif
 }
