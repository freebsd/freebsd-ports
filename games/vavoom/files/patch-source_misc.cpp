--- source/misc.cpp.orig	2022-12-31 03:37:54 UTC
+++ source/misc.cpp
@@ -119,7 +119,7 @@ void FOutputDevice::Logf(EName Type, const char* Fmt, 
 
 void VLogSysError::Serialise(const char* V, EName)
 {
-	Sys_Error(V);
+	Sys_Error("%s", V);
 }
 
 //==========================================================================
@@ -130,7 +130,7 @@ void VLogSysError::Serialise(const char* V, EName)
 
 void VLogHostError::Serialise(const char* V, EName)
 {
-	Host_Error(V);
+	Host_Error("%s", V);
 }
 
 //==========================================================================
