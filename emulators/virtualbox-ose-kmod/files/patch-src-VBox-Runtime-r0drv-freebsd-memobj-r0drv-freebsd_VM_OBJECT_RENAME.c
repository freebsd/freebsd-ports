$FreeBSD$

--- src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c	2013-03-20 14:45:46.594643103 -0700
+++ src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c	2013-03-20 14:33:00.483697105 -0700
@@ -162,7 +162,7 @@
         case RTR0MEMOBJTYPE_PHYS:
         case RTR0MEMOBJTYPE_PHYS_NC:
         {
-            VM_OBJECT_LOCK(pMemFreeBSD->pObject);
+            VM_OBJECT_RLOCK(pMemFreeBSD->pObject);
             vm_page_t pPage = vm_page_find_least(pMemFreeBSD->pObject, 0);
 #if __FreeBSD_version < 900000
             /* See http://lists.freebsd.org/pipermail/freebsd-current/2012-November/037963.html */
@@ -177,7 +177,7 @@
 #if __FreeBSD_version < 900000
             vm_page_unlock_queues();
 #endif
-            VM_OBJECT_UNLOCK(pMemFreeBSD->pObject);
+            VM_OBJECT_RUNLOCK(pMemFreeBSD->pObject);
             vm_object_deallocate(pMemFreeBSD->pObject);
             break;
         }
@@ -205,10 +205,10 @@
 
     while (cTries <= 1)
     {
-        VM_OBJECT_LOCK(pObject);
+        VM_OBJECT_RLOCK(pObject);
         pPages = vm_page_alloc_contig(pObject, iPIndex, fFlags, cPages, 0,
                                       VmPhysAddrHigh, uAlignment, 0, VM_MEMATTR_DEFAULT);
-        VM_OBJECT_UNLOCK(pObject);
+        VM_OBJECT_RUNLOCK(pObject);
         if (pPages)
             break;
         vm_pageout_grow_cache(cTries, 0, VmPhysAddrHigh);
@@ -228,7 +228,7 @@
 
     if (!pPages)
         return pPages;
-    VM_OBJECT_LOCK(pObject);
+    VM_OBJECT_RLOCK(pObject);
     for (vm_pindex_t iPage = 0; iPage < cPages; iPage++)
     {
         vm_page_t pPage = pPages + iPage;
@@ -240,7 +240,7 @@
             atomic_add_int(&cnt.v_wire_count, 1);
         }
     }
-    VM_OBJECT_UNLOCK(pObject);
+    VM_OBJECT_RUNLOCK(pObject);
     return pPages;
 #endif
 }
@@ -264,7 +264,7 @@
         if (!pPage)
         {
             /* Free all allocated pages */
-            VM_OBJECT_LOCK(pObject);
+            VM_OBJECT_RLOCK(pObject);
             while (iPage-- > 0)
             {
                 pPage = vm_page_lookup(pObject, iPage);
@@ -278,7 +278,7 @@
                 vm_page_unlock_queues();
 #endif
             }
-            VM_OBJECT_UNLOCK(pObject);
+            VM_OBJECT_RUNLOCK(pObject);
             return rcNoMem;
         }
     }
@@ -411,9 +411,9 @@
         if (fContiguous)
         {
             Assert(enmType == RTR0MEMOBJTYPE_PHYS);
-            VM_OBJECT_LOCK(pMemFreeBSD->pObject);
+            VM_OBJECT_RLOCK(pMemFreeBSD->pObject);
             pMemFreeBSD->Core.u.Phys.PhysBase = VM_PAGE_TO_PHYS(vm_page_find_least(pMemFreeBSD->pObject, 0));
-            VM_OBJECT_UNLOCK(pMemFreeBSD->pObject);
+            VM_OBJECT_RUNLOCK(pMemFreeBSD->pObject);
             pMemFreeBSD->Core.u.Phys.fAllocated = true;
         }
 
@@ -823,9 +823,9 @@
         case RTR0MEMOBJTYPE_PHYS_NC:
         {
             RTHCPHYS addr;
-            VM_OBJECT_LOCK(pMemFreeBSD->pObject);
+            VM_OBJECT_RLOCK(pMemFreeBSD->pObject);
             addr = VM_PAGE_TO_PHYS(vm_page_lookup(pMemFreeBSD->pObject, iPage));
-            VM_OBJECT_UNLOCK(pMemFreeBSD->pObject);
+            VM_OBJECT_RUNLOCK(pMemFreeBSD->pObject);
             return addr;
         }
 
