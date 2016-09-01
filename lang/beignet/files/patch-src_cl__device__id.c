--- src/cl_device_id.c.orig	2016-08-23 12:16:02.000000000 +0200
+++ src/cl_device_id.c	2016-08-31 17:50:49.806646000 +0200
@@ -35,7 +35,12 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
+#if defined(__linux__)
 #include <sys/sysinfo.h>
+#elif defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 
 #ifndef CL_VERSION_1_2
 #define CL_DEVICE_BUILT_IN_KERNELS 0x103F
@@ -269,6 +274,7 @@ LOCAL cl_device_id
 cl_get_gt_device(void)
 {
   cl_device_id ret = NULL;
+/* FIXME check cl_driver_get_device_id() */
   const int device_id = cl_driver_get_device_id();
   cl_device_id device = NULL;
 
@@ -737,7 +743,7 @@ kbl_gt4_break:
     case PCI_CHIP_SANDYBRIDGE_M_GT2_PLUS:
     case PCI_CHIP_SANDYBRIDGE_BRIDGE_S:
     case PCI_CHIP_SANDYBRIDGE_S_GT:
-      // Intel(R) HD Graphics SandyBridge not supported yet
+      printf("Intel(R) HD Graphics SandyBridge not supported yet\n");
       ret = NULL;
       break;
     default:
@@ -757,6 +763,7 @@ kbl_gt4_break:
   /* Apply any driver-dependent updates to the device info */
   cl_driver_update_device_info(ret);
 
+#if defined(__linux__)
   #define toMB(size) (size)&(0xfffffffffffffff<<20)
   /* Get the global_mem_size and max_mem_alloc size from
    * driver, system ram and hardware*/
@@ -776,6 +783,24 @@ kbl_gt4_break:
     ret->max_mem_alloc_size = toMB((ret->global_mem_size * 3 / 4 > maxallocmem) ?
                               maxallocmem: ret->global_mem_size * 3 / 4);
   }
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+  int mib[2];
+
+  mib[0] = CTL_HW;
+  mib[1] = HW_USERMEM;
+
+  uint64_t totalram;
+  size_t len;
+  len = sizeof(totalram);
+  sysctl(mib, 2, &totalram, &len, NULL, 0);
+
+  uint64_t two_gb = 2 * 1024 * 1024 * 1024ul;
+  ret->global_mem_size = (totalram > two_gb) ?
+                          two_gb : totalram;
+  ret->max_mem_alloc_size = ret->global_mem_size / 2;
+#else
+#error "not implimentend on this OS"
+#endif
 
   return ret;
 }
