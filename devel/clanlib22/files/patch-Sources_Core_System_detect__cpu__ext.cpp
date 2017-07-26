--- Sources/Core/System/detect_cpu_ext.cpp.orig	2011-01-27 08:46:22 UTC
+++ Sources/Core/System/detect_cpu_ext.cpp
@@ -30,6 +30,7 @@
 #include "Core/precomp.h"
 #include "API/Core/System/system.h"
 
+#ifndef CL_DISABLE_SSE2
 #if (defined(WIN32) || defined(_WIN32) || defined(_WIN64)) && !defined __MINGW32__
 #include <intrin.h>
 #endif
@@ -142,3 +143,4 @@ bool CL_System::detect_cpu_extension(CL_CPU_ExtensionX
 	return false;
 }
 
+#endif // not CL_DISABLE_SSE2
