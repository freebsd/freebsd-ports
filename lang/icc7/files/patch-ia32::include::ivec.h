--- ia32/include/ivec.h.orig	Fri Jan 10 18:12:39 2003
+++ ia32/include/ivec.h	Fri Jan 10 18:53:50 2003
@@ -24,7 +24,7 @@
 #include <assert.h>
 
 /* If using MSVC5.0, explicit keyword should be used */
-#if (_MSC_VER >= 1100) || defined (__linux__)
+#if (_MSC_VER >= 1100) || defined (__linux__) || defined (__FreeBSD__)
         #define EXPLICIT explicit
 #else
    #if (__INTEL_COMPILER)
