--- src/common/system/system_linux.cpp.orig	2021-12-03 22:35:25 UTC
+++ src/common/system/system_linux.cpp
@@ -98,7 +98,7 @@ void CSystemUtilsLinux::InterpolateTimeStamp(SystemTim
 
 void CSystemUtilsLinux::GetCurrentTimeStamp(SystemTimeStamp *stamp)
 {
-    clock_gettime(CLOCK_MONOTONIC_RAW, &stamp->clockTime);
+    clock_gettime(CLOCK_MONOTONIC, &stamp->clockTime);
 }
 
 long long CSystemUtilsLinux::TimeStampExactDiff(SystemTimeStamp *before, SystemTimeStamp *after)
