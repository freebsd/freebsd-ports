--- lib/CL/devices/cpuinfo.c.orig	2025-05-21 11:53:16 UTC
+++ lib/CL/devices/cpuinfo.c
@@ -34,6 +34,12 @@
 #include "config.h"
 #include "cpuinfo.h"
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#  include <sys/types.h>
+#  include <sys/sysctl.h>
+#endif
+
+#ifdef __linux__
 static const char* cpuinfo = "/proc/cpuinfo";
 #define MAX_CPUINFO_SIZE 64*1024
 //#define DEBUG_POCL_CPUINFO
@@ -41,9 +47,6 @@ static const char* cpufreq_file="/sys/devices/system/c
 //Linux' cpufrec interface
 static const char* cpufreq_file="/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq";
 
-// Vendor of PCI root bus
-static const char *pci_bus_root_vendor_file = "/sys/bus/pci/devices/0000:00:00.0/vendor";
-
 /* Strings to parse in /proc/cpuinfo. Else branch is for x86, x86_64 */
 #if   defined  __powerpc__
  #define FREQSTRING "clock"
@@ -156,8 +159,51 @@ pocl_cpuinfo_detect_max_clock_frequency()
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
+int
+pocl_cpuinfo_detect_max_clock_frequency()
+{
+  return 0;
+}
+#endif
 
+#ifdef __linux__
 /**
  * Detects the number of parallel hardware threads supported by
  * the CPU by parsing the cpuinfo.
@@ -235,6 +281,19 @@ pocl_cpuinfo_detect_compute_unit_count()
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
 
 #if __arm__ || __aarch64__
 enum
@@ -302,6 +361,7 @@ pocl_cpuinfo_get_cpu_name_and_vendor(cl_device_id devi
    * short_name is in the .data anyways.*/
   device->long_name = device->short_name;
 
+#ifdef __linux__ 
   /* default vendor and vendor_id, in case it cannot be found by other means */
   device->vendor = cpuvendor_default;
   if (device->vendor_id == 0)
@@ -408,7 +468,26 @@ pocl_cpuinfo_get_cpu_name_and_vendor(cl_device_id devi
   snprintf (new_name, len, "%s-%s-%s", device->short_name,
             (device->llvm_cpu ? device->llvm_cpu : ""), start);
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
+
   /* If the vendor_id field is still empty, we should get the PCI ID associated
    * with the CPU vendor (if there is one), to be ready for the (currently
    * provisional) OpenCL 3.0 specification that has finally clarified the
@@ -419,13 +498,23 @@ pocl_cpuinfo_get_cpu_name_and_vendor(cl_device_id devi
    */
   if (!device->vendor_id)
     {
-      f = fopen (pci_bus_root_vendor_file, "r");
+#if		defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+		/*
+		*	Future work: try to extract vendor ID from PCI root bus from MIB
+		*/
+#elif	defined(__linux__)
+      FILE *f = fopen (pci_bus_root_vendor_file, "r");
       if (f)
         {
           /* no error checking, if it failed we just won't have the info */
           num_read = fscanf (f, "%x", &device->vendor_id);
           fclose (f);
         }
+#else
+		/*
+		*		Other aliens ...
+		*/
+#endif
     }
 }
 
