Index: src/VBox/Runtime/r0drv/freebsd/the-freebsd-kernel.h
===================================================================
--- src/VBox/Runtime/r0drv/freebsd/the-freebsd-kernel.h	(Revision 58727)
+++ src/VBox/Runtime/r0drv/freebsd/the-freebsd-kernel.h	(Arbeitskopie)
@@ -64,6 +64,8 @@
 #include <vm/vm_kern.h>
 #include <vm/vm_param.h>        /* KERN_SUCCESS ++ */
 #include <vm/vm_page.h>
+#include <vm/vm_phys.h>         /* vm_phys_alloc_* */
+#include <sys/vmmeter.h>        /* cnt */
 #include <sys/resourcevar.h>
 #include <machine/cpu.h>
 
