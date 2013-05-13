--- src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c.orig	2013-05-10 15:16:34.000000000 +0200
+++ src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c	2013-05-10 12:43:20.000000000 +0200
@@ -165,7 +165,11 @@
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
@@ -177,8 +181,14 @@
             {
                 vm_page_unwire(pPage, 0);
             }
+#if __FreeBSD_version < 900000
             vm_page_unlock_queues();
+#endif
+#if __FreeBSD_version >= 1000030
+            VM_OBJECT_WUNLOCK(pMemFreeBSD->pObject);
+#else
             VM_OBJECT_UNLOCK(pMemFreeBSD->pObject);
+#endif
             vm_object_deallocate(pMemFreeBSD->pObject);
             break;
         }
@@ -205,9 +215,17 @@
         flags |= VM_ALLOC_WIRED;
     while (1)
     {
+#if __FreeBSD_version >= 1000030
+        VM_OBJECT_WLOCK(pObject);
+#else
         VM_OBJECT_LOCK(pObject);
+#endif
         pPages = vm_page_alloc_contig(pObject, iPIndex, flags, cPages, 0, VmPhysAddrHigh, uAlignment, 0, VM_MEMATTR_DEFAULT);
+#if __FreeBSD_version >= 1000030
+        VM_OBJECT_WUNLOCK(pObject);
+#else
         VM_OBJECT_UNLOCK(pObject);
+#endif
         if (pPages || tries >= 1)
             break;
         vm_pageout_grow_cache(tries, 0, VmPhysAddrHigh);
@@ -226,7 +244,11 @@
     }
     if (!pPages)
         return pPages;
+#if __FreeBSD_version >= 1000030
+    VM_OBJECT_WLOCK(pObject);
+#else
     VM_OBJECT_LOCK(pObject);
+#endif
     for (vm_pindex_t iPage = 0; iPage < cPages; iPage++)
     {
         vm_page_t pPage = pPages + iPage;
@@ -238,7 +260,11 @@
             atomic_add_int(&cnt.v_wire_count, 1);
         }
     }
+#if __FreeBSD_version >= 1000030
+    VM_OBJECT_WUNLOCK(pObject);
+#else
     VM_OBJECT_UNLOCK(pObject);
+#endif
     return pPages;
 #endif
 }
@@ -261,7 +287,11 @@
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
@@ -271,9 +301,15 @@
                 if (fWire)
                     vm_page_unwire(pPage, 0);
                 vm_page_free(pPage);
+#if __FreeBSD_version < 900000
                 vm_page_unlock_queues();
+#endif
             }
+#if __FreeBSD_version >= 1000030
+            VM_OBJECT_WUNLOCK(pObject);
+#else
             VM_OBJECT_UNLOCK(pObject);
+#endif
             return VERR_NO_MEMORY;
         }
     }
@@ -406,9 +442,17 @@
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
 
@@ -813,9 +857,17 @@
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
 
