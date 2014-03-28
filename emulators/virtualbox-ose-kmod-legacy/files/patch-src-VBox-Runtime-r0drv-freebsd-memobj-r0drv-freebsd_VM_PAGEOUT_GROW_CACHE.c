--- src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c.orig	2014-03-17 14:08:04.000000000 -0400
+++ src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c	2014-03-17 14:09:34.000000000 -0400
@@ -211,7 +211,7 @@
     if (fWire)
         fFlags |= VM_ALLOC_WIRED;
 
-    while (cTries <= 1)
+    while (1)
     {
 #if __FreeBSD_version >= 1000030
         VM_OBJECT_WLOCK(pObject);
@@ -225,18 +225,22 @@
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
 
     return pPages;
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
