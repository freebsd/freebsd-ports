--- src/ScanSDK/Src/SDK/supervisor.cpp.orig	2021-11-25 00:56:59 UTC
+++ src/ScanSDK/Src/SDK/supervisor.cpp
@@ -282,7 +282,7 @@ bool Supervisor::DeviceInfoResolve(SDIDeviceInfo* devI
 }
 bool Supervisor::CheckScanningError(SDIError outError)
 {
-    if(outEventType == 10 ){
+    if(outEventType == (SDITransferEventType)10 ){
         if(outError != kSDIErrorNone){
             m_LastError = outError;
             return false;
@@ -2541,7 +2541,7 @@ bool Supervisor::Set_All_Value(void)
         }
         {
             SDIInt current;
-            if(device_data.ScanArea.FixedSize == USER_DEFINE){
+            if(device_data.ScanArea.FixedSize == (DocumentSize)USER_DEFINE){
                 current = device_data.ScanArea.PaperEndDetection.select;
             }else {
                 current = false;
@@ -3487,7 +3487,7 @@ bool Supervisor::Set_Exclusion_Value(void)
         }
         {
             SDIInt current;
-            if(device_data.ScanArea.FixedSize == USER_DEFINE){
+            if(device_data.ScanArea.FixedSize == (DocumentSize)USER_DEFINE){
                 current = device_data.ScanArea.PaperEndDetection.select;
             }else {
                 current = false;
