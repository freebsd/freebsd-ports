From Alan L. Cox on FreeBSD-current:

    I just glanced at the virtualbox code for a couple minutes. For
    FreeBSD 9 and 10, these lock acquires are completely unnecessary, and
    have been since FreeBSD 9.0. Just delete them. They may be equally
    unnecessary under FreeBSD 8, but I didn't look carefully enough to
    answer that question.

[1] http://lists.freebsd.org/pipermail/freebsd-current/2012-November/037963.html

--- src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c.orig	2012-12-19 20:51:59.000000000 +0100
+++ src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c	2012-12-20 15:14:56.283850834 +0100
@@ -136,7 +136,10 @@
                                 (vm_offset_t)pMemFreeBSD->Core.pv + pMemFreeBSD->Core.cb);
             AssertMsg(rc == KERN_SUCCESS, ("%#x", rc));
 
+#if __FreeBSD_version < 900000
+            /* See http://lists.freebsd.org/pipermail/freebsd-current/2012-November/037963.html */
             vm_page_lock_queues();
+#endif
             for (uint32_t iPage = 0; iPage < pMemFreeBSD->u.Phys.cPages; iPage++)
             {
                 vm_page_t pPage = pMemFreeBSD->u.Phys.apPages[iPage];
@@ -191,7 +194,9 @@
         case RTR0MEMOBJTYPE_PHYS:
         case RTR0MEMOBJTYPE_PHYS_NC:
         {
+#if __FreeBSD_version < 900000
             vm_page_lock_queues();
+#endif
             for (uint32_t iPage = 0; iPage < pMemFreeBSD->u.Phys.cPages; iPage++)
             {
                 vm_page_t pPage = pMemFreeBSD->u.Phys.apPages[iPage];
@@ -266,7 +271,9 @@
                 while (iPage-- > 0)
                 {
                     pPage = pMemFreeBSD->u.Phys.apPages[iPage];
+#if __FreeBSD_version < 900000
                     vm_page_lock_queues();
+#endif
                     vm_page_unwire(pPage, 0);
                     vm_page_free(pPage);
                     vm_page_unlock_queues();
@@ -448,7 +455,9 @@
                 while (iPage-- > 0)
                 {
                     pPage = pMemFreeBSD->u.Phys.apPages[iPage];
+#if __FreeBSD_version < 900000
                     vm_page_lock_queues();
+#endif
                     vm_page_unwire(pPage, 0);
                     vm_page_free(pPage);
                     vm_page_unlock_queues();
