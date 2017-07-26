--- Sources/Core/System/detect_cpu_ext.cpp.orig	2011-11-15 12:15:42 UTC
+++ Sources/Core/System/detect_cpu_ext.cpp
@@ -30,6 +30,7 @@
 #include "Core/precomp.h"
 #include "API/Core/System/system.h"
 
+#ifndef CL_DISABLE_SSE2
 #ifdef CL_ARM_PLATFORM
 bool CL_System::detect_cpu_extension(CL_CPU_ExtensionPPC ext)
 {
@@ -183,3 +184,4 @@ bool CL_System::detect_cpu_extension(CL_CPU_ExtensionX
 }
 
 #endif
+#endif // not CL_DISABLE_SSE2
