--- src/core/utilities.cpp.orig	2012-10-30 17:49:07.162325275 +0400
+++ src/core/utilities.cpp	2012-10-30 17:50:58.101950562 +0400
@@ -520,13 +520,9 @@ bool IsLaptop() {
   }
 
   return !(status.BatteryFlag & 128); // 128 = no system battery
-#endif
-
-#ifdef Q_OS_LINUX
+#elif Q_OS_LINUX
   return !QDir("/proc/acpi/battery").entryList(QDir::Dirs | QDir::NoDotAndDotDot).isEmpty();
-#endif
-
-#ifdef Q_OS_MAC
+#elif Q_OS_MAC
   ScopedCFTypeRef<CFTypeRef> power_sources(IOPSCopyPowerSourcesInfo());
   ScopedCFTypeRef<CFArrayRef> power_source_list(
       IOPSCopyPowerSourcesList(power_sources.get()));
@@ -540,6 +536,8 @@ bool IsLaptop() {
     }
   }
   return false;
+#else
+  return false;
 #endif
 }
 
