--- ia32/include/dvec.h.orig	Fri Jan 10 18:12:30 2003
+++ ia32/include/dvec.h	Fri Jan 10 18:53:34 2003
@@ -38,7 +38,7 @@
 
 
 /* If using MSVC5.0, explicit keyword should be used */
-#if (_MSC_VER >= 1100) || defined (__linux__)
+#if (_MSC_VER >= 1100) || defined (__linux__) || defined (__FreeBSD__)
         #define EXPLICIT explicit
 #else
    #if (__INTEL_COMPILER)
@@ -50,10 +50,10 @@
 #endif
 
 /* Figure out whether and how to define the output operators */
-#if defined(_IOSTREAM_) || defined(_CPP_IOSTREAM)
+#if defined(_IOSTREAM_) || defined(_CPP_IOSTREAM) || defined(_STLP_IOSTREAM)
 #define DVEC_DEFINE_OUTPUT_OPERATORS
 #define DVEC_STD std::
-#elif defined(_INC_IOSTREAM) || defined(_IOSTREAM_H_)
+#elif defined(_INC_IOSTREAM) || defined(_IOSTREAM_H_) || defined(_STLP_IOSTREAM_H)
 #define DVEC_DEFINE_OUTPUT_OPERATORS
 #define DVEC_STD
 #endif
