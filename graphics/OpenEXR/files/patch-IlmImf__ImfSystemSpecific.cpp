--- IlmImf/ImfSystemSpecific.cpp.orig	2014-08-10 04:23:57 UTC
+++ IlmImf/ImfSystemSpecific.cpp
@@ -35,6 +35,9 @@
 #include "ImfSystemSpecific.h"
 #include "ImfNamespace.h"
 #include "OpenEXRConfig.h"
+#if defined(IMF_HAVE_SSE2) &&  defined(__GNUC__)
+#include <cpuid.h>
+#endif
 
 OPENEXR_IMF_INTERNAL_NAMESPACE_SOURCE_ENTER
 
@@ -44,11 +47,7 @@ namespace {
     // Helper functions for gcc + SSE enabled
     void cpuid(int n, int &eax, int &ebx, int &ecx, int &edx)
     {
-        __asm__ __volatile__ (
-            "cpuid"
-            : /* Output  */ "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx) 
-            : /* Input   */ "a"(n)
-            : /* Clobber */);
+	__cpuid(n, eax, ebx, ecx, edx);
     }
 
 #else // IMF_HAVE_SSE2 && __GNUC__
