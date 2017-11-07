--- src/VBox/Runtime/r0drv/freebsd/the-freebsd-kernel.h.orig	2017-04-18 09:53:54 UTC
+++ src/VBox/Runtime/r0drv/freebsd/the-freebsd-kernel.h
@@ -60,6 +60,7 @@
 #include <sys/smp.h>
 #include <sys/sleepqueue.h>
 #include <sys/sx.h>
+#include <sys/vmmeter.h>        /* vm_cnt */
 #include <vm/vm.h>
 #include <vm/pmap.h>            /* for vtophys */
 #include <vm/vm_map.h>
@@ -70,7 +71,6 @@
 #include <vm/vm_phys.h>         /* vm_phys_alloc_* */
 #include <vm/vm_extern.h>       /* kmem_alloc_attr */
 #include <vm/vm_pageout.h>      /* vm_contig_grow_cache */
-#include <sys/vmmeter.h>        /* cnt */
 #include <sys/resourcevar.h>
 #include <machine/cpu.h>
 
