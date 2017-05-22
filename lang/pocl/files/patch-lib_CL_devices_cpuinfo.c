--- lib/CL/devices/cpuinfo.c.orig	2017-04-05 14:15:40 UTC
+++ lib/CL/devices/cpuinfo.c
@@ -34,6 +34,12 @@
 #include "config.h"
 #include "cpuinfo.h"
 
+#ifdef HAVE_SYSCTL_H
+#  include <sys/types.h>
+#  include <sys/sysctl.h>
+#endif
+
+#ifdef __linux__
 static const char* cpuinfo = "/proc/cpuinfo";
 #define MAX_CPUINFO_SIZE 64*1024
 //#define DEBUG_POCL_CPUINFO
@@ -153,8 +159,51 @@ pocl_cpuinfo_detect_max_clock_frequency(
     } 
   return -1;  
 }
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
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
+  const char mib1[] = "dev.cpu.0.freq_levels";
+  const char mib2[] = "hw.clockrate";
+  int clockrate = 0;
+  size_t size = 0;
+  char *value = NULL;
 
+  if (!sysctlbyname(mib1, NULL, &size, NULL, 0) &&
+      (value = (char*)malloc(++size)) &&
+      !sysctlbyname(mib1, (void*)value, &size, NULL, 0))
+    {
+      value[size] = '\0';
+      sscanf(value, "%d/%*d", &clockrate);
+    }
+  else
+    {
+      size = sizeof(clockrate); 
+      sysctlbyname(mib2, (void*)&clockrate, &size, NULL, 0);
+    }
+  if (value)
+    free(value);
+  return clockrate;
+}
+#else
+/**
+ * Unimplemented for other platforms.
+ */
+ int
+pocl_cpuinfo_detect_max_clock_frequency()
+{
+  return 0;
+}
+#endif
 
+#ifdef __linux__
 /**
  * Detects the number of parallel hardware threads supported by
  * the CPU by parsing the cpuinfo.
@@ -232,6 +281,19 @@ pocl_cpuinfo_detect_compute_unit_count()
     } 
   return -1;  
 }
+#else
+/**
+ * Detects the number of parallel hardware threads supported by
+ * the CPU.
+ *
+ * @return The number of hardware threads.
+ */
+ int
+pocl_cpuinfo_detect_compute_unit_count()
+{
+  return sysconf(_SC_NPROCESSORS_ONLN);
+}
+#endif
 
 #ifdef POCL_ANDROID
 
@@ -270,6 +332,7 @@ pocl_cpuinfo_get_cpu_name_and_vendor(cl_
    * short_name is in the .data anyways.*/
   device->long_name = device->short_name;
 
+#ifdef __linux__ 
   /* default vendor and vendor_id, in case it cannot be found by other means */
   device->vendor = cpuvendor_default;
   if (device->vendor_id == 0)
@@ -318,7 +381,25 @@ pocl_cpuinfo_get_cpu_name_and_vendor(cl_
   char *new_name = (char*)malloc (len);
   snprintf (new_name, len, "%s-%s", device->short_name, start);
   device->long_name = new_name;
+#elif defined(HAVE_SYSCTL_H)
+  int mib[2];
+  size_t len = 0;
+  char *model;
 
+  mib[0] = CTL_HW;
+  mib[1] = HW_MODEL;
+  if (sysctl(mib, 2, NULL, &len, NULL, 0))
+    return;
+  if (!(model = (char*)malloc(++len)))
+    return;
+  if (sysctl(mib, 2, (void*)model, &len, NULL, 0))
+    free(model);
+  else
+    {
+      model[len] = '\0';
+      device->long_name = model;
+    }
+#endif
 }
 
 void
