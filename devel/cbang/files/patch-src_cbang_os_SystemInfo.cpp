--- src/cbang/os/SystemInfo.cpp.orig	2021-08-10 22:46:49 UTC
+++ src/cbang/os/SystemInfo.cpp
@@ -64,6 +64,13 @@
 
 #include "MacOSUtilities.h"
 
+#elif defined(__FreeBSD__)
+#include <sys/sysinfo.h>
+#include <sys/utsname.h>
+#include <sys/sysctl.h>
+#include <sys/ucred.h>
+#include <unistd.h>
+
 #else // !_MSC_VER && !__APPLE__
 #include <sys/sysinfo.h>
 #include <sys/utsname.h>
@@ -90,7 +97,7 @@ uint32_t SystemInfo::getCPUCount() const {
   GetSystemInfo(&sysinfo);
   return sysinfo.dwNumberOfProcessors;
 
-#elif defined(__APPLE__) || defined(__FreeBSD__)
+#elif defined(__APPLE__)
   int nm[2];
   size_t length = 4;
   uint32_t count;
@@ -127,7 +134,7 @@ uint64_t SystemInfo::getMemoryInfo(memory_info_t type)
     return (uint64_t)(info.ullAvailPhys + info.ullAvailPageFile);
   }
 
-#elif defined(__APPLE__) || defined(__FreeBSD__)
+#elif defined(__APPLE__)
   if (type == MEM_INFO_TOTAL) {
     int64_t memory;
     int mib[2];
