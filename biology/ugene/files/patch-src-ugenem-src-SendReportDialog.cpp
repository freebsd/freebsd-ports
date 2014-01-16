--- src/ugenem/src/SendReportDialog.cpp.orig
+++ src/ugenem/src/SendReportDialog.cpp
@@ -44,6 +44,10 @@
 #include <Winbase.h> //for IsProcessorFeaturePresent
 #endif
 
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
+#include <unistd.h> // for sysconf(3)
+#endif
+
 #define HOST_URL "http://ugene.unipro.ru"
 //#define HOST_URL "http://127.0.0.1"
 #define DESTINATION_URL_KEEPER_PAGE "/crash_reports_dest.html"
@@ -241,6 +245,8 @@ QString ReportSender::getOSVersion() {
 
 #elif defined(Q_OS_LINUX)
     result = "Linux";
+#elif defined(Q_OS_FREEBSD)
+    result = "FreeBSD";
 #elif defined(Q_OS_MAC)
     result = "Mac ";
     switch (QSysInfo::MacintoshVersion){
@@ -304,17 +310,15 @@ int ReportSender::getTotalPhysicalMemory
         totalPhysicalMemory = memory_status.ullTotalPhys / (1024 * 1024);
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
