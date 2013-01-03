--- ./src/VBox/Runtime/r0drv/freebsd/the-freebsd-kernel.h.orig	2012-06-12 02:54:01.440878507 +0400
+++ ./src/VBox/Runtime/r0drv/freebsd/the-freebsd-kernel.h	2012-06-12 00:08:55.218232972 +0400
@@ -64,6 +64,7 @@
 #include <vm/vm_kern.h>
 #include <vm/vm_param.h>        /* KERN_SUCCESS ++ */
 #include <vm/vm_page.h>
+#include <vm/vm_pageout.h>
 #include <vm/vm_phys.h>         /* vm_phys_alloc_* */
 #include <vm/vm_extern.h>       /* kmem_alloc_attr */
 #include <sys/vmmeter.h>        /* cnt */
