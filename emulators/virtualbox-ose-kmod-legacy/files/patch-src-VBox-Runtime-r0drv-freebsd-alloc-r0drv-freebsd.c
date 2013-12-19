--- src/VBox/Runtime/r0drv/freebsd/alloc-r0drv-freebsd.c	2013-09-06 06:30:30.000000000 -0600
+++ src/VBox/Runtime/r0drv/freebsd/alloc-r0drv-freebsd.c	2013-09-18 12:01:45.000000000 -0600
@@ -79,8 +79,13 @@
             return VERR_NO_EXEC_MEMORY;
 
         /* Addr contains a start address vm_map_find will start searching for suitable space at. */
+#if __FreeBSD_version >= 1000055
+        int rc = vm_map_find(kernel_map, pVmObject, 0, &Addr,
+                             cbAllocated, 0, VMFS_ANY_SPACE, VM_PROT_ALL, VM_PROT_ALL, 0);
+#else
         int rc = vm_map_find(kernel_map, pVmObject, 0, &Addr,
                              cbAllocated, TRUE, VM_PROT_ALL, VM_PROT_ALL, 0);
+#endif
         if (rc == KERN_SUCCESS)
         {
             rc = vm_map_wire(kernel_map, Addr, Addr + cbAllocated,
