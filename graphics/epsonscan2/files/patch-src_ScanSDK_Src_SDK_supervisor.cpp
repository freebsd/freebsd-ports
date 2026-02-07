--- src/ScanSDK/Src/SDK/supervisor.cpp.orig	2024-09-12 07:10:37 UTC
+++ src/ScanSDK/Src/SDK/supervisor.cpp
@@ -284,7 +284,7 @@ bool Supervisor::CheckScanningError(SDIError outError)
 }
 bool Supervisor::CheckScanningError(SDIError outError)
 {
-    if(outEventType == 10 ){
+    if(outEventType == (SDITransferEventType)10 ){
         if(outError != kSDIErrorNone){
             m_LastError = outError;
             return false;
@@ -2627,7 +2627,7 @@ bool Supervisor::Set_All_Value(void)
         }
         {
             SDIInt current;
-            if(device_data.ScanArea.FixedSize == USER_DEFINE){
+            if(device_data.ScanArea.FixedSize == (DocumentSize)USER_DEFINE){
                 current = device_data.ScanArea.PaperEndDetection.select;
             }else {
                 current = false;
@@ -3607,7 +3607,7 @@ bool Supervisor::Set_Exclusion_Value(void)
         }
         {
             SDIInt current;
-            if(device_data.ScanArea.FixedSize == USER_DEFINE){
+            if(device_data.ScanArea.FixedSize == (DocumentSize)USER_DEFINE){
                 current = device_data.ScanArea.PaperEndDetection.select;
             }else {
                 current = false;
