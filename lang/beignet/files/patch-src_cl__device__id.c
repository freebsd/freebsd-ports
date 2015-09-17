diff --git a/src/cl_device_id.c b/src/cl_device_id.c
index e9e2c16..5f35248 100644
--- src/cl_device_id.c
+++ src/cl_device_id.c
@@ -34,7 +34,12 @@
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
@@ -202,6 +207,7 @@ LOCAL cl_device_id
 cl_get_gt_device(void)
 {
   cl_device_id ret = NULL;
+/* FIXME check cl_driver_get_device_id() */
   const int device_id = cl_driver_get_device_id();
   cl_device_id device = NULL;
 
@@ -526,7 +532,7 @@ skl_gt4_break:
     case PCI_CHIP_SANDYBRIDGE_M_GT2_PLUS:
     case PCI_CHIP_SANDYBRIDGE_BRIDGE_S:
     case PCI_CHIP_SANDYBRIDGE_S_GT:
-      // Intel(R) HD Graphics SandyBridge not supported yet
+      printf("Intel(R) HD Graphics SandyBridge not supported yet\n");
       ret = NULL;
       break;
     default:
@@ -546,6 +552,7 @@ skl_gt4_break:
   /* Apply any driver-dependent updates to the device info */
   cl_driver_update_device_info(ret);
 
+#if defined(__linux__)
   struct sysinfo info;
   if (sysinfo(&info) == 0) {
     uint64_t two_gb = 2 * 1024 * 1024 * 1024ul; 
@@ -554,6 +561,24 @@ skl_gt4_break:
                             two_gb : info.totalram;
     ret->max_mem_alloc_size = ret->global_mem_size / 2;
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
