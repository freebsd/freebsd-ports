--- src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c.orig	2015-12-18 16:22:29 UTC
+++ src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c
@@ -168,7 +168,7 @@ DECLHIDDEN(int) rtR0MemObjNativeFree(RTR
             VM_OBJECT_LOCK(pMemFreeBSD->pObject);
 #endif
             vm_page_t pPage = vm_page_find_least(pMemFreeBSD->pObject, 0);
-#if __FreeBSD_version < 1000000
+#if __FreeBSD_version < 900000
             vm_page_lock_queues();
 #endif
             for (vm_page_t pPage = vm_page_find_least(pMemFreeBSD->pObject, 0);
@@ -177,7 +177,7 @@ DECLHIDDEN(int) rtR0MemObjNativeFree(RTR
             {
                 vm_page_unwire(pPage, 0);
             }
-#if __FreeBSD_version < 1000000
+#if __FreeBSD_version < 900000
             vm_page_unlock_queues();
 #endif
 #if __FreeBSD_version >= 1000030
@@ -205,12 +205,12 @@ static vm_page_t rtR0MemObjFreeBSDContig
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
@@ -224,18 +224,23 @@ static vm_page_t rtR0MemObjFreeBSDContig
 #else
         VM_OBJECT_UNLOCK(pObject);
 #endif
-        if (pPages)
+        if (pPages || cTries >= 1)
             break;
+#if __FreeBSD_version >= 1100092
+        if (!vm_page_reclaim_contig(fFlags, cPages, 0, VmPhysAddrHigh, uAlignment, 0))
+            break;
+#elif __FreeBSD_version >= 1000015
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
@@ -243,11 +248,8 @@ static vm_page_t rtR0MemObjFreeBSDContig
 
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
@@ -259,13 +261,9 @@ static vm_page_t rtR0MemObjFreeBSDContig
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
@@ -295,13 +293,13 @@ static int rtR0MemObjFreeBSDPhysAllocHel
             while (iPage-- > 0)
             {
                 pPage = vm_page_lookup(pObject, iPage);
-#if __FreeBSD_version < 1000000
+#if __FreeBSD_version < 900000
                 vm_page_lock_queues();
 #endif
                 if (fWire)
                     vm_page_unwire(pPage, 0);
                 vm_page_free(pPage);
-#if __FreeBSD_version < 1000000
+#if __FreeBSD_version < 900000
                 vm_page_unlock_queues();
 #endif
             }
@@ -751,7 +749,12 @@ DECLHIDDEN(int) rtR0MemObjNativeMapUser(
     {
         /** @todo: is this needed?. */
         PROC_LOCK(pProc);
-        AddrR3 = round_page((vm_offset_t)pProc->p_vmspace->vm_daddr + lim_max(pProc, RLIMIT_DATA));
+        AddrR3 = round_page((vm_offset_t)pProc->p_vmspace->vm_daddr +
+#if __FreeBSD_version >= 1100077
+                            lim_max_proc(pProc, RLIMIT_DATA));
+#else
+                            lim_max(pProc, RLIMIT_DATA));
+#endif
         PROC_UNLOCK(pProc);
     }
     else
