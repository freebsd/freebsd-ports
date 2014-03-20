From Alan L. Cox on FreeBSD-current:

    I just glanced at the virtualbox code for a couple minutes.  For
    FreeBSD 9 and 10, these lock acquires are completely unnecessary, and
    have been since FreeBSD 9.0.  Just delete them.  They may be equally
    unnecessary under FreeBSD 8, but I didn't look carefully enough to
    answer that question.

[1] http://lists.freebsd.org/pipermail/freebsd-current/2012-November/037963.html
--- src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c.orig	2014-02-25 12:09:32.000000000 -0500
+++ src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c	2014-03-17 13:57:00.000000000 -0400
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
@@ -201,12 +206,12 @@
     vm_page_t pPages;
     int cTries = 0;
 
-#if __FreeBSD_version > 1000000
+#if __FreeBSD_version >= 902508
     int fFlags = VM_ALLOC_INTERRUPT | VM_ALLOC_NOBUSY;
     if (fWire)
         fFlags |= VM_ALLOC_WIRED;
 
-    while (cTries <= 1)
+    while (1)
     {
 #if __FreeBSD_version >= 1000030
         VM_OBJECT_WLOCK(pObject);
@@ -220,18 +225,20 @@
 #else
         VM_OBJECT_UNLOCK(pObject);
 #endif
-        if (pPages)
+        if (pPages || cTries >= 1)
             break;
+#if __FreeBSD_version >= 1000015
         vm_pageout_grow_cache(cTries, 0, VmPhysAddrHigh);
+#else
+        vm_contig_grow_cache(cTries, 0, VmPhysAddrHigh);
+#endif
         cTries++;
     }
-
-    return pPages;
 #else
-    while (cTries <= 1)
+    while (1)
     {
         pPages = vm_phys_alloc_contig(cPages, 0, VmPhysAddrHigh, uAlignment, 0);
-        if (pPages)
+        if (pPages || cTries >= 1)
             break;
         vm_contig_grow_cache(cTries, 0, VmPhysAddrHigh);
         cTries++;
@@ -239,11 +246,8 @@
 
     if (!pPages)
         return pPages;
-#if __FreeBSD_version >= 1000030
-    VM_OBJECT_WLOCK(pObject);
-#else
+
     VM_OBJECT_LOCK(pObject);
-#endif
     for (vm_pindex_t iPage = 0; iPage < cPages; iPage++)
     {
         vm_page_t pPage = pPages + iPage;
@@ -255,13 +259,9 @@
             atomic_add_int(&cnt.v_wire_count, 1);
         }
     }
-#if __FreeBSD_version >= 1000030
-    VM_OBJECT_WUNLOCK(pObject);
-#else
     VM_OBJECT_UNLOCK(pObject);
 #endif
     return pPages;
-#endif
 }
 
 static int rtR0MemObjFreeBSDPhysAllocHelper(vm_object_t pObject, u_long cPages,
@@ -291,11 +291,15 @@
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
