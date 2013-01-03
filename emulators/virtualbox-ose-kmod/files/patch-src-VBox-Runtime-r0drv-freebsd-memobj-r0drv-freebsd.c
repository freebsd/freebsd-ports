From Alan L. Cox on FreeBSD-current:

    I just glanced at the virtualbox code for a couple minutes.  For
    FreeBSD 9 and 10, these lock acquires are completely unnecessary, and
    have been since FreeBSD 9.0.  Just delete them.  They may be equally
    unnecessary under FreeBSD 8, but I didn't look carefully enough to
    answer that question.

[1] http://lists.freebsd.org/pipermail/freebsd-current/2012-November/037963.html
---
 src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c | 9 +++++++++
 1 file changed, 9 insertions(+)

diff --git a/src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c b/src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c
index 5c90cf3..1176b51 100644
--- src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c
+++ src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c
@@ -164,14 +164,19 @@ DECLHIDDEN(int) rtR0MemObjNativeFree(RTR0MEMOBJ pMem)
         {
             VM_OBJECT_LOCK(pMemFreeBSD->pObject);
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
             VM_OBJECT_UNLOCK(pMemFreeBSD->pObject);
             vm_object_deallocate(pMemFreeBSD->pObject);
             break;
@@ -263,11 +268,15 @@ static int rtR0MemObjFreeBSDPhysAllocHelper(vm_object_t pObject, u_long cPages,
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
             VM_OBJECT_UNLOCK(pObject);
             return rcNoMem;
-- 
1.7.11.5

