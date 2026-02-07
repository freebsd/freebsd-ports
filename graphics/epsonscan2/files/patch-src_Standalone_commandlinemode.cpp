--- src/Standalone/commandlinemode.cpp.orig	2024-09-12 07:10:40 UTC
+++ src/Standalone/commandlinemode.cpp
@@ -535,7 +535,7 @@ void CommandLineMode::ErrorMessage(SDIError outError)
         }else if(outError == kSDIErrorPaperProtect){
             error_message = "ERROR : A paper jam has occurred. See the documentation for instructions on removing your originals.";
         }else if(outError == kSDIErrorDeviceInBusy){
-            error_message = "kSDIErrorDeviceInBusy";
+            error_message = "ERROR : kSDIErrorDeviceInBusy";
         }else if(outError == kSDIErrorCoverOpen){
             error_message = "ERROR : ADF or ADF cover is open. Close it and reload the originals.";
         }else if(outError == kSDIErrorTrayClose){
@@ -556,6 +556,8 @@ void CommandLineMode::ErrorMessage(SDIError outError)
             error_message = "ERROR : Device is not found...";
         }else if(outError == kSDIErrorUserAuthEnabled){
             error_message = "ERROR : Scanning from Epson Scan 2 is not allowed because the authentication function for the scanner is enabled.";
+        }else if(outError == kSDIErrorInvalidResponse){
+            error_message = "ERROR : kSDIErrorInvalidResponse";
         }else if(outError == kSDIErrorPaperRemoveError){
             error_message = "ERROR : Remove the original.";
         }else if(outError == kSDIErrorSkewDetectError){
