--- src/Standalone/supervisor.cpp.orig	2021-11-25 00:56:57 UTC
+++ src/Standalone/supervisor.cpp
@@ -270,7 +270,7 @@ bool Supervisor::DeviceInfoResolve(SDIDeviceInfo* devI
 }
 bool Supervisor::CheckScanningError(SDIError outError)
 {
-    if(outEventType == 10 ){
+    if(outEventType == (SDITransferEventType)10 ){
         if(outError != kSDIErrorNone){
             m_LastError = outError;
             return false;
@@ -2632,7 +2632,7 @@ bool Supervisor::Set_All_Value(void)
         }
         {
             SDIInt current;
-            if(device_data.ScanArea.FixedSize == USER_DEFINE){
+            if(device_data.ScanArea.FixedSize == (DocumentSize)USER_DEFINE){
                 current = device_data.ScanArea.PaperEndDetection.select;
             }else {
                 current = false;
@@ -3712,7 +3712,7 @@ bool Supervisor::Set_Exclusion_Value(void)
         }
         {
             SDIInt current;
-            if(device_data.ScanArea.FixedSize == USER_DEFINE){
+            if(device_data.ScanArea.FixedSize == (DocumentSize)USER_DEFINE){
                 current = device_data.ScanArea.PaperEndDetection.select;
             }else {
                 current = false;
