--- include/fvec.h.orig	Sat Jun  4 17:36:19 2005
+++ include/fvec.h	Sat Jun  4 17:45:48 2005
@@ -41,7 +41,7 @@
 #pragma pack(push,16) /* Must ensure class & union 16-B aligned */
 
 /* If using MSVC5.0, explicit keyword should be used */
-#if (_MSC_VER >= 1100) || defined (__linux__) || defined(__QNX__)
+#if (_MSC_VER >= 1100) || defined (__linux__) || defined(__QNX__) || defined (__FreeBSD__)
         #define EXPLICIT explicit
 #else
    #if (__INTEL_COMPILER)
@@ -53,10 +53,10 @@
 #endif
 
 /* Figure out whether and how to define the output operators */
-#if defined(_IOSTREAM_) || defined(_CPP_IOSTREAM)
+#if defined(_IOSTREAM_) || defined(_CPP_IOSTREAM) || defined(_STLP_IOSTREAM)
 #define FVEC_DEFINE_OUTPUT_OPERATORS
 #define FVEC_STD std::
-#elif defined(_INC_IOSTREAM) || defined(_IOSTREAM_H_)
+#elif defined(_INC_IOSTREAM) || defined(_IOSTREAM_H_) || defined(_STLP_IOSTREAM_H)
 #define FVEC_DEFINE_OUTPUT_OPERATORS
 #define FVEC_STD
 #endif
