--- include/ivec.h.orig	Tue Dec  9 20:16:16 2003
+++ include/ivec.h	Tue Dec  9 20:36:38 2003
@@ -23,7 +23,7 @@
 #include <assert.h>
 
 /* If using MSVC5.0, explicit keyword should be used */
-#if (_MSC_VER >= 1100) || defined (__linux__)
+#if (_MSC_VER >= 1100) || defined (__linux__) || defined (__FreeBSD__)
         #define EXPLICIT explicit
 #else
    #if (__INTEL_COMPILER)
@@ -35,10 +35,10 @@
 #endif
 
 /* Figure out whether and how to define the output operators */
-#if defined(_IOSTREAM_) || defined(_CPP_IOSTREAM)
+#if defined(_IOSTREAM_) || defined(_CPP_IOSTREAM) || defined(_STLP_IOSTREAM)
 #define IVEC_DEFINE_OUTPUT_OPERATORS
 #define IVEC_STD std::
-#elif defined(_INC_IOSTREAM) || defined(_IOSTREAM_H_)
+#elif defined(_INC_IOSTREAM) || defined(_IOSTREAM_H_) || defined(_STLP_IOSTREAM_H)
 #define IVEC_DEFINE_OUTPUT_OPERATORS
 #define IVEC_STD
 #endif
