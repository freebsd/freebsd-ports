--- modules/javafx.web/src/main/native/Source/bmalloc/bmalloc/AvailableMemory.cpp.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.web/src/main/native/Source/bmalloc/bmalloc/AvailableMemory.cpp
@@ -47,6 +47,11 @@
 #if BOS(LINUX)
 #include <algorithm>
 #include <fcntl.h>
+#elif BOS(FREEBSD)
+#include "VMAllocate.h"
+#include <sys/sysctl.h>
+#include <sys/types.h>
+#include <sys/user.h>
 #endif
 #include <unistd.h>
 #endif
@@ -184,7 +189,7 @@ size_t availableMemory()
     return availableMemory;
 }
 
-#if BPLATFORM(IOS_FAMILY) || BOS(LINUX)
+#if BPLATFORM(IOS_FAMILY) || BOS(LINUX) || BOS(FREEBSD)
 MemoryStatus memoryStatus()
 {
 #if BPLATFORM(IOS_FAMILY)
@@ -200,6 +205,21 @@ MemoryStatus memoryStatus()
     auto& memory = LinuxMemory::singleton();
     size_t memoryFootprint = memory.footprint();
     double percentInUse = static_cast<double>(memoryFootprint) / static_cast<double>(memory.availableMemory);
+#elif BOS(FREEBSD)
+    struct kinfo_proc info;
+    size_t infolen = sizeof(info);
+
+    int mib[4];
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC;
+    mib[2] = KERN_PROC_PID;
+    mib[3] = getpid();
+
+    size_t memoryFootprint = 0;
+    if (!sysctl(mib, 4, &info, &infolen, nullptr, 0))
+        memoryFootprint = static_cast<size_t>(info.ki_rssize) * vmPageSize();
+
+    double percentInUse = static_cast<double>(memoryFootprint) / static_cast<double>(availableMemory());
 #endif
 
     double percentAvailableMemoryInUse = std::min(percentInUse, 1.0);
