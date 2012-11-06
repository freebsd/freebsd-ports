--- sdl/i_system.c.orig
+++ sdl/i_system.c
@@ -83,10 +83,7 @@
 #  include <sys/mount.h>
 /*For meminfo*/
 #  include <sys/types.h>
-#  include <kvm.h>
-#  include <nlist.h>
-#  include <sys/vmmeter.h>
-#  include <fcntl.h>
+#  include <sys/sysctl.h>
 # endif
 #endif
 
@@ -832,30 +829,16 @@ uint64_t I_GetFreeMem(uint64_t *total)
   // LINUX covers all the unix-type OS's.
 
 #ifdef FREEBSD
-    struct  vmmeter sum;
-    kvm_t *kd;
-    struct nlist namelist[]= {
-#define X_SUM   0
-	{"_cnt"},
-	{ NULL }
-    };
-    if ((kd = kvm_open(NULL, NULL, NULL, O_RDONLY, "kvm_open")) == NULL)
+    unsigned long page_count, free_count, pagesize;
+    size_t len = sizeof(unsigned long);
+    if (sysctlbyname("vm.stats.vm.v_page_count", &page_count, &len, NULL, 0))
       goto guess;
-
-    if (kvm_nlist(kd, namelist) != 0)
-    {
-	kvm_close (kd);
-	goto guess;
-    }
-    if (kvm_read(kd,namelist[X_SUM].n_value ,&sum, sizeof(sum)) != sizeof(sum))
-    {
-	kvm_close (kd);
-	goto guess;
-    }
-    kvm_close (kd);
-
-    *total = sum.v_page_count * sum.v_page_size;
-    return sum.v_free_count * sum.v_page_size;
+    if (sysctlbyname("vm.stats.vm.v_free_count", &free_count, &len, NULL, 0))
+      goto guess;
+    if (sysctlbyname("hw.pagesize", &pagesize, &len, NULL, 0))
+      goto guess;
+    *total = page_count * pagesize;
+    return free_count * pagesize;
 #elif defined(SOLARIS)
     goto guess;
 #else
