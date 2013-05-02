--- src/VBox/Runtime/r0drv/freebsd/the-freebsd-kernel.h.orig	2013-03-05 14:28:07.000000000 +0000
+++ src/VBox/Runtime/r0drv/freebsd/the-freebsd-kernel.h	2013-03-28 13:10:34.000000000 +0000
@@ -50,6 +50,9 @@
 #include <sys/unistd.h>
 #include <sys/kthread.h>
 #include <sys/lock.h>
+#if __FreeBSD_version >= 1000030
+#include <sys/rwlock.h>
+#endif
 #include <sys/mutex.h>
 #include <sys/sched.h>
 #include <sys/callout.h>
@@ -64,6 +67,7 @@
 #include <vm/vm_kern.h>
 #include <vm/vm_param.h>        /* KERN_SUCCESS ++ */
 #include <vm/vm_page.h>
+#include <vm/vm_pageout.h>
 #include <vm/vm_phys.h>         /* vm_phys_alloc_* */
 #include <vm/vm_extern.h>       /* kmem_alloc_attr */
 #include <sys/vmmeter.h>        /* cnt */
