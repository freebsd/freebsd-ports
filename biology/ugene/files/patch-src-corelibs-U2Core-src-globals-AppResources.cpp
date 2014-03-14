--- src/corelibs/U2Core/src/globals/AppResources.cpp.orig
+++ src/corelibs/U2Core/src/globals/AppResources.cpp
@@ -35,6 +35,10 @@
 #include <proc/readproc.h>
 #endif
 
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
+#include <unistd.h> // for sysconf(3) and getpid(2)
+#endif
+
 #ifdef Q_OS_WIN
 #include <windows.h>
 #include <Psapi.h>
@@ -88,17 +92,15 @@ int AppResourcePool::getTotalPhysicalMem
         coreLog.error("Total physical memory: getting info error");
     }
 
-#elif defined(Q_OS_LINUX)
-    QProcess p;
-    p.start("awk", QStringList() << "/MemTotal/ {print $2}" << "/proc/meminfo");
-    p.waitForFinished();
-    QString memory = p.readAllStandardOutput();
-    p.close();
-    bool ok = false;
-    qlonglong output_mem = memory.toLongLong(&ok);
-    if (ok) {
-        totalPhysicalMemory = output_mem / 1024;
-    }
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
+    long pagesize = sysconf(_SC_PAGESIZE);
+    long numpages = sysconf(_SC_PHYS_PAGES);
+
+    // Assume that page size is always a multiple of 1024, so it can be
+    // divided without losing any precision.  On the other hand, number
+    // of pages would hardly overflow `long' when multiplied by a small
+    // number (number of pages / 1024), so we should be safe here.
+    totalPhysicalMemory = (int)(numpages * (pagesize / 1024) / 1024);
 
 #elif defined(Q_OS_MAC)
 // TODO
@@ -143,15 +145,27 @@ void AppResourcePool::setMaxMemorySizeIn
 
 size_t AppResourcePool::getCurrentAppMemory() {
 
-#ifdef Q_OS_LINUX
-    struct proc_t usage;
-    //look_up_our_self(&usage);
-    return usage.vsize;
-#endif
 #ifdef Q_OS_WIN
     PROCESS_MEMORY_COUNTERS memCounter;
     bool result = GetProcessMemoryInfo(GetCurrentProcess(), &memCounter, sizeof( memCounter ));
     return memCounter.WorkingSetSize;
+#elif defined(Q_OS_LINUX)
+    struct proc_t usage;
+    //look_up_our_self(&usage);
+    return usage.vsize;
+#elif defined(Q_OS_FREEBSD)
+     QProcess p;
+     p.start("ps", QStringList() << "-o" << "vsize=" << "-p" << QString("%1").arg(getpid()));
+     p.waitForFinished();
+     QString ps_vsize = p.readAllStandardOutput();
+     p.close();
+     bool ok = false;
+     qlonglong output_mem = ps_vsize.toLongLong(&ok);
+     if (ok) {
+         return output_mem / 1024;
+     }
+#else
+    coreLog.error("Current application memory: Unsupported OS");
 #endif
 }
 
