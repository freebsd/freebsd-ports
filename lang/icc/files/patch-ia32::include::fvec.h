--- ia32/include/fvec.h.orig	Fri Jan 10 18:12:35 2003
+++ ia32/include/fvec.h	Fri Jan 10 18:54:01 2003
@@ -41,7 +41,7 @@
 #pragma pack(push,16) /* Must ensure class & union 16-B aligned */
 
 /* If using MSVC5.0, explicit keyword should be used */
-#if (_MSC_VER >= 1100) || defined (__linux__)
+#if (_MSC_VER >= 1100) || defined (__linux__) || defined (__FreeBSD__)
         #define EXPLICIT explicit
 #else
    #if (__INTEL_COMPILER)
