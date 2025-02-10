--- JuceLibraryCode/modules/juce_core/native/juce_SystemStats_linux.cpp.orig	2024-12-21 22:21:33 UTC
+++ JuceLibraryCode/modules/juce_core/native/juce_SystemStats_linux.cpp
@@ -56,7 +56,11 @@ SystemStats::OperatingSystemType SystemStats::getOpera
 
 String SystemStats::getOperatingSystemName()
 {
+#ifdef __FreeBSD__
+    return "FreeBSD";
+#else
     return "Linux";
+#endif
 }
 
 bool SystemStats::isOperatingSystem64Bit()
@@ -318,18 +322,17 @@ String SystemStats::getUniqueDeviceID()
             return {};
         };
 
-        auto data = call ("cat /sys/class/dmi/id/board_serial");
+        auto data = call ("kenv smbios.planar.serial");
 
         // 'board_serial' is enough on its own, fallback to bios stuff if we can't find it.
         if (data.isEmpty())
         {
-            data = call ("cat /sys/class/dmi/id/bios_date")
-                 + call ("cat /sys/class/dmi/id/bios_release")
-                 + call ("cat /sys/class/dmi/id/bios_vendor")
-                 + call ("cat /sys/class/dmi/id/bios_version");
+            data = call ("kenv smbios.bios.reldate")
+                 + call ("kenv smbios.bios.vendor")
+                 + call ("kenv smbios.bios.version");
         }
 
-        auto cpuData = call ("lscpu");
+        auto cpuData = String {};
 
         if (cpuData.isNotEmpty())
         {
