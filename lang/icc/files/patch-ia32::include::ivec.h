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
@@ -36,10 +36,10 @@
 #endif
 
 /* Figure out whether and how to define the output operators */
-#if defined(_IOSTREAM_)
+#if defined(_IOSTREAM_) || defined(_STLP_IOSTREAM)
 #define IVEC_DEFINE_OUTPUT_OPERATORS
 #define IVEC_STD std::
-#elif defined(_INC_IOSTREAM) || defined(_IOSTREAM_H_)
+#elif defined(_INC_IOSTREAM) || defined(_IOSTREAM_H_) || defined(_STLP_IOSTREAM_H)
 #define IVEC_DEFINE_OUTPUT_OPERATORS
 #define IVEC_STD
 #endif
