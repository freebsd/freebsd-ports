--- src/VBox/Runtime/r0drv/freebsd/the-freebsd-kernel.h.orig	2018-10-15 14:31:31 UTC
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
 
@@ -114,6 +114,24 @@
  */
 #if 0 /** @todo Not available yet. */
 # define USE_KMEM_ALLOC_PROT
+#endif
+
+/** 
+ * Macros for preserving EFLAGS.AC (despair / paranoid)
+ */
+#if __FreeBSD_version >= 1200076 && defined(RT_ARCH_AMD64)
+# include <iprt/asm-amd64-x86.h>
+# include <iprt/x86.h>
+# define IPRT_FREEBSD_SAVE_EFL_AC()             RTCCUINTREG const fSavedEfl = ASMGetFlags()
+# define IPRT_FREEBSD_RESTORE_EFL_AC()          ASMSetFlags(fSavedEfl)
+# define IPRT_FREEBSD_RESTORE_EFL_ONLY_AC()     ASMChangeFlags(~X86_EFL_AC, fSavedEfl & X86_EFL_AC)
+# define IPRT_FREEBSD_RESTORE_EFL_ONLY_AC_EX(f) ASMChangeFlags(~X86_EFL_AC, (f) & X86_EFL_AC)
+# define VBOX_WITH_EFLAGS_AC_SET_IN_VBOXDRV
+#else
+# define IPRT_FREEBSD_SAVE_EFL_AC()             do { } while (0)
+# define IPRT_FREEBSD_RESTORE_EFL_AC()          do { } while (0)
+# define IPRT_FREEBSD_RESTORE_EFL_ONLY_AC()     do { } while (0)
+# define IPRT_FREEBSD_RESTORE_EFL_ONLY_AC_EX(f) do { } while (0)
 #endif
 
 #endif
