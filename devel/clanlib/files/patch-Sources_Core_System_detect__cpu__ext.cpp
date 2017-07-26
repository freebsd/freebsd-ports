--- Sources/Core/System/detect_cpu_ext.cpp.orig	2011-11-15 12:15:42 UTC
+++ Sources/Core/System/detect_cpu_ext.cpp
@@ -30,7 +30,7 @@
 #include "Core/precomp.h"
 #include "API/Core/System/system.h"
 
-#ifdef CL_ARM_PLATFORM
+#if defined(CL_ARM_PLATFORM) || defined(CL_DISABLE_SSE2)
 bool CL_System::detect_cpu_extension(CL_CPU_ExtensionPPC ext)
 {
 	throw ("Congratulations, you've just been selected to code this feature!");
