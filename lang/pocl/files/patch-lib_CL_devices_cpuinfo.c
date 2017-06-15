--- lib/CL/devices/cpuinfo.c.orig	2016-11-20 11:31:19.521203000 +0100
+++ lib/CL/devices/cpuinfo.c	2016-11-20 11:29:24.502817000 +0100
@@ -31,9 +31,13 @@
 #  include "vccompat.hpp"
 #endif
 
+#include <sys/types.h>
+#include <sys/sysctl.h>
+
 #include "config.h"
 #include "cpuinfo.h"
 
+#if 0
 const char* cpuinfo = "/proc/cpuinfo";
 #define MAX_CPUINFO_SIZE 64*1024
 //#define DEBUG_POCL_CPUINFO
@@ -152,8 +156,29 @@ pocl_cpuinfo_detect_max_clock_frequency(
     } 
   return -1;  
 }
+#endif
+
+/**
+ * Detects the number of parallel hardware threads supported by
+ * the CPU.
+ *
+ * @return The number of hardware threads.
+ */
+ int
+pocl_cpuinfo_detect_compute_unit_count()
+{
+  int mib[2], nocpus;
+  size_t len;
 
+  mib[0] = CTL_HW;
+  mib[1] = HW_NCPU;
+  len = sizeof(nocpus);
+  sysctl(mib, 2, &nocpus, &len, NULL, 0);
 
+  return nocpus;
+}
+
+#if 0
 /**
  * Detects the number of parallel hardware threads supported by
  * the CPU by parsing the cpuinfo.
@@ -231,6 +256,27 @@ pocl_cpuinfo_detect_compute_unit_count()
     } 
   return -1;  
 }
+#endif
+
+/**
+ * Detects the maximum clock frequency of the CPU.
+ *
+ * Assumes all cores have the same max clock freq.
+ *
+ * @return The clock frequency in MHz.
+ */
+int
+pocl_cpuinfo_detect_max_clock_frequency()
+{
+  //XXX PLEASE NOTE, THIS IS NOT TOO PORTABLE (AND/OR ACCURATE)!
+  const char mib[] = "hw.clockrate";
+  size_t size = sizeof(int);
+  int clockrate;
+
+  sysctlbyname(mib, (void *)&clockrate, &size, NULL, 0);
+  
+  return clockrate;
+ }
 
 #ifdef POCL_ANDROID
 
@@ -269,6 +315,7 @@ pocl_cpuinfo_get_cpu_name_and_vendor(cl_
    * short_name is in the .data anyways.*/
   device->long_name = device->short_name;
 
+#if 0
   /* default vendor and vendor_id, in case it cannot be found by other means */
   device->vendor = cpuvendor_default;
   if (device->vendor_id == 0)
@@ -317,6 +364,7 @@ pocl_cpuinfo_get_cpu_name_and_vendor(cl_
   char *new_name = (char*)malloc (len);
   snprintf (new_name, len, "%s-%s", device->short_name, start);
   device->long_name = new_name;
+#endif
 
 }
 
