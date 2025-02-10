--- src/Controller/Src/Scanner/Scanner.cpp.orig	2024-09-12 07:10:36 UTC
+++ src/Controller/Src/Scanner/Scanner.cpp
@@ -183,7 +183,7 @@ void Scanner::EngineCallBackReceiver(EngineEventType e
        error == kSDIErrorDataSend ||
      error == kSDIErrorInvalidResponse ||
     error == kSDIErrorDeviceFatalError ||
-    error == kESErrorDeviceOpenError )
+    error == (SDIError) kESErrorDeviceOpenError )
    {
     SDI_TRACE_LOG("communication error occurs");
     isOpened_ = false;
@@ -197,13 +197,13 @@ SDIError Scanner::Open()
  SDIError err;
  if (engine_) {
   err = engine_->Open();
-  if(err != kSDIErrorNone){
+  if(err != kSDIErrorNone && err != kSDIErrorDeviceOpen){
    return err;
   }
  }
  if (engineSecond_) {
   err = engineSecond_->Open();
-  if(err != kSDIErrorNone){
+  if(err != kSDIErrorNone && err != kSDIErrorDeviceOpen){
    return err;
   }
  }
