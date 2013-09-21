--- src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c.orig	2013-09-06 12:30:30.000000000 +0000
+++ src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c	2013-09-21 18:12:53.000000000 +0000
@@ -286,9 +286,15 @@
     pMemFreeBSD->pObject = vm_object_allocate(OBJT_PHYS, cPages);
 
     /* No additional object reference for auto-deallocation upon unmapping. */
+#if __FreeBSD_version >= 1000055
+    rc = vm_map_find(kernel_map, pMemFreeBSD->pObject, 0,
+                     &MapAddress, pMemFreeBSD->Core.cb, 0, VMFS_ANY_SPACE,
+                     fExecutable ? VM_PROT_ALL : VM_PROT_RW, VM_PROT_ALL, 0);
+#else
     rc = vm_map_find(kernel_map, pMemFreeBSD->pObject, 0,
                      &MapAddress, pMemFreeBSD->Core.cb, VMFS_ANY_SPACE,
                      fExecutable ? VM_PROT_ALL : VM_PROT_RW, VM_PROT_ALL, 0);
+#endif
 
     if (rc == KERN_SUCCESS)
     {
@@ -551,6 +557,9 @@
                      0,                             /* offset */
                      &MapAddress,                   /* addr (IN/OUT) */
                      cb,                            /* length */
+#if __FreeBSD_version >= 1000055
+                     0,                             /* max addr */
+#endif
                      pvFixed == (void *)-1 ? VMFS_ANY_SPACE : VMFS_NO_SPACE,
                                                     /* find_space */
                      VM_PROT_NONE,                  /* protection */
@@ -628,6 +637,9 @@
                      offSub,                /* Start offset in the object */
                      &Addr,                 /* Start address IN/OUT */
                      cbSub,                 /* Size of the mapping */
+#if __FreeBSD_version >= 1000055
+                     0,                     /* Upper bound of mapping */
+#endif
                      VMFS_ANY_SPACE,        /* Whether a suitable address should be searched for first */
                      ProtectionFlags,       /* protection flags */
                      VM_PROT_ALL,           /* Maximum protection flags */
@@ -704,6 +716,9 @@
                      0,                     /* Start offset in the object */
                      &AddrR3,               /* Start address IN/OUT */
                      pMemToMap->cb,         /* Size of the mapping */
+#if __FreeBSD_version >= 1000055
+                     0,                     /* Upper bound of the mapping */
+#endif
                      R3PtrFixed == (RTR3PTR)-1 ? VMFS_ANY_SPACE : VMFS_NO_SPACE,
                                             /* Whether a suitable address should be searched for first */
                      ProtectionFlags,       /* protection flags */
