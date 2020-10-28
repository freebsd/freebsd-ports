--- modules/javafx.web/src/main/native/Source/WTF/wtf/linux/MemoryPressureHandlerLinux.cpp.orig	2020-07-17 12:21:33 UTC
+++ modules/javafx.web/src/main/native/Source/WTF/wtf/linux/MemoryPressureHandlerLinux.cpp
@@ -28,13 +28,20 @@
 #include "config.h"
 #include <wtf/MemoryPressureHandler.h>
 
-#include <malloc.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <wtf/MainThread.h>
 #include <wtf/MemoryFootprint.h>
-#include <wtf/linux/CurrentProcessMemoryStatus.h>
 #include <wtf/text/WTFString.h>
 
+#if OS(LINUX)
+#include <wtf/linux/CurrentProcessMemoryStatus.h>
+#elif OS(FREEBSD)
+#include <sys/sysctl.h>
+#include <sys/types.h>
+#include <sys/user.h>
+#endif
+
 #define LOG_CHANNEL_PREFIX Log
 
 namespace WTF {
@@ -105,9 +112,28 @@ void MemoryPressureHandler::holdOff(Seconds seconds)
 
 static size_t processMemoryUsage()
 {
+#if OS(LINUX)
     ProcessMemoryStatus memoryStatus;
     currentProcessMemoryStatus(memoryStatus);
     return (memoryStatus.resident - memoryStatus.shared);
+#elif OS(FREEBSD)
+    static size_t pageSize = sysconf(_SC_PAGE_SIZE);
+    struct kinfo_proc info;
+    size_t infolen = sizeof(info);
+
+    int mib[4];
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC;
+    mib[2] = KERN_PROC_PID;
+    mib[3] = getpid();
+
+    if (sysctl(mib, 4, &info, &infolen, nullptr, 0))
+        return 0;
+
+    return static_cast<size_t>(info.ki_rssize - info.ki_tsize) * pageSize;
+#else
+#error "Missing a platform specific way of determining the memory usage"
+#endif
 }
 
 void MemoryPressureHandler::respondToMemoryPressure(Critical critical, Synchronous synchronous)
