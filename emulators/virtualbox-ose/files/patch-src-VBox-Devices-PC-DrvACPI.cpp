--- src/VBox/Devices/PC/DrvACPI.cpp.orig	2013-11-29 14:23:31.000000000 -0500
+++ src/VBox/Devices/PC/DrvACPI.cpp	2013-12-13 17:36:50.000000000 -0500
@@ -204,7 +204,7 @@
     int fAcLine = 0;
     size_t cbParameter = sizeof(fAcLine);
 
-    int rc = sysctlbyname("hw.acpi.acline", &fAcLine, &cbParameter, NULL, NULL);
+    int rc = sysctlbyname("hw.acpi.acline", &fAcLine, &cbParameter, NULL, 0);
 
     if (!rc)
     {
@@ -463,7 +463,7 @@
         int fBatteryState = 0;
         size_t cbParameter = sizeof(fBatteryState);
 
-        rc = sysctlbyname("hw.acpi.battery.state", &fBatteryState, &cbParameter, NULL, NULL);
+        rc = sysctlbyname("hw.acpi.battery.state", &fBatteryState, &cbParameter, NULL, 0);
         if (!rc)
         {
             if ((fBatteryState & ACPI_BATT_STAT_NOT_PRESENT) == ACPI_BATT_STAT_NOT_PRESENT)
@@ -485,7 +485,7 @@
                 /* Get battery level. */
                 int curCapacity = 0;
                 cbParameter = sizeof(curCapacity);
-                rc = sysctlbyname("hw.acpi.battery.life", &curCapacity, &cbParameter, NULL, NULL);
+                rc = sysctlbyname("hw.acpi.battery.life", &curCapacity, &cbParameter, NULL, 0);
                 if (!rc && curCapacity >= 0)
                     *penmRemainingCapacity = (PDMACPIBATCAPACITY)curCapacity;
 
