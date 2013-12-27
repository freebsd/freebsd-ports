From Alan L. Cox on FreeBSD-current:

    I just glanced at the virtualbox code for a couple minutes.  For
    FreeBSD 9 and 10, these lock acquires are completely unnecessary, and
    have been since FreeBSD 9.0.  Just delete them.  They may be equally
    unnecessary under FreeBSD 8, but I didn't look carefully enough to
    answer that question.

[1] http://lists.freebsd.org/pipermail/freebsd-current/2012-November/037963.html
--- src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c.orig	2013-11-29 12:04:53.000000000 +0100
+++ src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c	2013-11-29 12:37:29.000000000 +0100
@@ -168,14 +168,19 @@
             VM_OBJECT_LOCK(pMemFreeBSD->pObject);
 #endif
             vm_page_t pPage = vm_page_find_least(pMemFreeBSD->pObject, 0);
+#if __FreeBSD_version < 900000
+            /* See http://lists.freebsd.org/pipermail/freebsd-current/2012-November/037963.html */
             vm_page_lock_queues();
+#endif
             for (vm_page_t pPage = vm_page_find_least(pMemFreeBSD->pObject, 0);
                  pPage != NULL;
                  pPage = vm_page_next(pPage))
             {
                 vm_page_unwire(pPage, 0);
             }
+#if __FreeBSD_version < 900000
             vm_page_unlock_queues();
+#endif
 #if __FreeBSD_version >= 1000030
             VM_OBJECT_WUNLOCK(pMemFreeBSD->pObject);
 #else
@@ -291,11 +296,15 @@
             while (iPage-- > 0)
             {
                 pPage = vm_page_lookup(pObject, iPage);
+#if __FreeBSD_version < 900000
                 vm_page_lock_queues();
+#endif
                 if (fWire)
                     vm_page_unwire(pPage, 0);
                 vm_page_free(pPage);
+#if __FreeBSD_version < 900000
                 vm_page_unlock_queues();
+#endif
             }
 #if __FreeBSD_version >= 1000030
             VM_OBJECT_WUNLOCK(pObject);
