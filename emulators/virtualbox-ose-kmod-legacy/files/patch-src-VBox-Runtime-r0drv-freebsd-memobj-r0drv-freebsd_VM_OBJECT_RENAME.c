$FreeBSD$

--- src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c.orig	2014-03-14 17:25:46.000000000 -0400
+++ src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c	2014-03-14 17:34:35.000000000 -0400
@@ -162,7 +162,11 @@
         case RTR0MEMOBJTYPE_PHYS:
         case RTR0MEMOBJTYPE_PHYS_NC:
         {
+#if __FreeBSD_version >= 1000030
+            VM_OBJECT_WLOCK(pMemFreeBSD->pObject);
+#else
             VM_OBJECT_LOCK(pMemFreeBSD->pObject);
+#endif
             vm_page_t pPage = vm_page_find_least(pMemFreeBSD->pObject, 0);
 #if __FreeBSD_version < 900000
             /* See http://lists.freebsd.org/pipermail/freebsd-current/2012-November/037963.html */
@@ -177,7 +181,11 @@
 #if __FreeBSD_version < 900000
             vm_page_unlock_queues();
 #endif
+#if __FreeBSD_version >= 1000030
+            VM_OBJECT_WUNLOCK(pMemFreeBSD->pObject);
+#else
             VM_OBJECT_UNLOCK(pMemFreeBSD->pObject);
+#endif
             vm_object_deallocate(pMemFreeBSD->pObject);
             break;
         }
@@ -198,17 +206,25 @@
     vm_page_t pPages;
     int cTries = 0;
 
-#if __FreeBSD_version > 1000000
+#if __FreeBSD_version >= 902508
     int fFlags = VM_ALLOC_INTERRUPT | VM_ALLOC_NOBUSY;
     if (fWire)
         fFlags |= VM_ALLOC_WIRED;
 
     while (cTries <= 1)
     {
+#if __FreeBSD_version >= 1000030
+        VM_OBJECT_WLOCK(pObject);
+#else
         VM_OBJECT_LOCK(pObject);
+#endif
         pPages = vm_page_alloc_contig(pObject, iPIndex, fFlags, cPages, 0,
                                       VmPhysAddrHigh, uAlignment, 0, VM_MEMATTR_DEFAULT);
+#if __FreeBSD_version >= 1000030
+        VM_OBJECT_WUNLOCK(pObject);
+#else
         VM_OBJECT_UNLOCK(pObject);
+#endif
         if (pPages)
             break;
         vm_pageout_grow_cache(cTries, 0, VmPhysAddrHigh);
@@ -264,7 +280,11 @@
         if (!pPage)
         {
             /* Free all allocated pages */
+#if __FreeBSD_version >= 1000030
+            VM_OBJECT_WLOCK(pObject);
+#else
             VM_OBJECT_LOCK(pObject);
+#endif
             while (iPage-- > 0)
             {
                 pPage = vm_page_lookup(pObject, iPage);
@@ -278,7 +298,11 @@
                 vm_page_unlock_queues();
 #endif
             }
+#if __FreeBSD_version >= 1000030
+            VM_OBJECT_WUNLOCK(pObject);
+#else
             VM_OBJECT_UNLOCK(pObject);
+#endif
             return rcNoMem;
         }
     }
@@ -417,9 +441,17 @@
         if (fContiguous)
         {
             Assert(enmType == RTR0MEMOBJTYPE_PHYS);
+#if __FreeBSD_version >= 1000030
+            VM_OBJECT_WLOCK(pMemFreeBSD->pObject);
+#else
             VM_OBJECT_LOCK(pMemFreeBSD->pObject);
+#endif
             pMemFreeBSD->Core.u.Phys.PhysBase = VM_PAGE_TO_PHYS(vm_page_find_least(pMemFreeBSD->pObject, 0));
+#if __FreeBSD_version >= 1000030
+            VM_OBJECT_WUNLOCK(pMemFreeBSD->pObject);
+#else
             VM_OBJECT_UNLOCK(pMemFreeBSD->pObject);
+#endif
             pMemFreeBSD->Core.u.Phys.fAllocated = true;
         }
 
@@ -838,9 +870,17 @@
         case RTR0MEMOBJTYPE_PHYS_NC:
         {
             RTHCPHYS addr;
+#if __FreeBSD_version >= 1000030
+            VM_OBJECT_WLOCK(pMemFreeBSD->pObject);
+#else
             VM_OBJECT_LOCK(pMemFreeBSD->pObject);
+#endif
             addr = VM_PAGE_TO_PHYS(vm_page_lookup(pMemFreeBSD->pObject, iPage));
+#if __FreeBSD_version >= 1000030
+            VM_OBJECT_WUNLOCK(pMemFreeBSD->pObject);
+#else
             VM_OBJECT_UNLOCK(pMemFreeBSD->pObject);
+#endif
             return addr;
         }
 
