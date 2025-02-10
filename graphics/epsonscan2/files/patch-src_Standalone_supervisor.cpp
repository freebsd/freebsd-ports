--- src/Standalone/supervisor.cpp.orig	2024-09-12 07:10:42 UTC
+++ src/Standalone/supervisor.cpp
@@ -297,7 +297,7 @@ bool Supervisor::CheckScanningError(SDIError outError)
 }
 bool Supervisor::CheckScanningError(SDIError outError)
 {
-    if (outEventType == 10)
+    if (outEventType == (SDITransferEventType)10)
     {
         if (outError != kSDIErrorNone)
         {
@@ -3127,7 +3127,7 @@ bool Supervisor::Set_All_Value(void)
         }
         {
             SDIInt current;
-            if (device_data.ScanArea.FixedSize == USER_DEFINE)
+            if (device_data.ScanArea.FixedSize == (DocumentSize)USER_DEFINE)
             {
                 current = device_data.ScanArea.PaperEndDetection.select;
             }
@@ -4352,7 +4352,7 @@ bool Supervisor::Set_Exclusion_Value(void)
         }
         {
             SDIInt current;
-            if (device_data.ScanArea.FixedSize == USER_DEFINE)
+            if (device_data.ScanArea.FixedSize == (DocumentSize)USER_DEFINE)
             {
                 current = device_data.ScanArea.PaperEndDetection.select;
             }
