--- os_dep.c.orig	2012-07-25 15:08:26.000000000 +0300
+++ os_dep.c	2012-07-25 15:16:54.000000000 +0300
@@ -843,7 +843,7 @@
     GC_INNER void GC_set_and_save_fault_handler(GC_fault_handler_t h)
     {
 #       if defined(SUNOS5SIGS) || defined(IRIX5) \
-           || defined(OSF1) || defined(HURD) || defined(NETBSD)
+           || defined(OSF1) || defined(HURD) || defined(NETBSD) || defined(FREEBSD)
           struct sigaction act;
 
           act.sa_handler = h;
@@ -3072,8 +3072,15 @@
 #     ifndef SEGV_ACCERR
 #       define SEGV_ACCERR 2
 #     endif
-#     define CODE_OK (si -> si_code == BUS_PAGE_FAULT \
+#     if defined(POWERPC)
+#      define AIM      /* Pretend that we're AIM. */
+#      include <machine/trap.h>
+#       define CODE_OK (si -> si_code == EXC_DSI \
+          || si -> si_code == SEGV_ACCERR)
+#     else
+#       define CODE_OK (si -> si_code == BUS_PAGE_FAULT \
           || si -> si_code == SEGV_ACCERR)
+#     endif
 #   elif defined(OSF1)
 #     define CODE_OK (si -> si_code == 2 /* experimentally determined */)
 #   elif defined(IRIX5)
