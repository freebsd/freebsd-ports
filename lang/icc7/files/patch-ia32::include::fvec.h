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
@@ -53,10 +53,10 @@
 #endif
 
 /* Figure out whether and how to define the output operators */
-#if defined(_IOSTREAM_)
+#if defined(_IOSTREAM_) || defined(_STLP_IOSTREAM)
 #define FVEC_DEFINE_OUTPUT_OPERATORS
 #define FVEC_STD std::
-#elif defined(_INC_IOSTREAM) || defined(_IOSTREAM_H_)
+#elif defined(_INC_IOSTREAM) || defined(_IOSTREAM_H_) || defined(_STLP_IOSTREAM_H)
 #define FVEC_DEFINE_OUTPUT_OPERATORS
 #define FVEC_STD
 #endif
