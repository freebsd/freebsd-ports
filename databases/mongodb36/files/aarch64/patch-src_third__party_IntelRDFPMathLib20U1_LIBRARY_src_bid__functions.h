--- src/third_party/IntelRDFPMathLib20U1/LIBRARY/src/bid_functions.h.orig	2018-12-13 15:47:17 UTC
+++ src/third_party/IntelRDFPMathLib20U1/LIBRARY/src/bid_functions.h
@@ -42,7 +42,7 @@
 #include <ctype.h>
 
 // Fix system header issue on Sun solaris and define required type by ourselves
-#if !defined(_WCHAR_T) && !defined(_WCHAR_T_DEFINED) && !defined(__QNX__)
+#if !defined(_WCHAR_T) && !defined(_WCHAR_T_DEFINED) && !defined(__QNX__) && !defined(_WCHAR_T_DECLARED)
 typedef int   wchar_t;
 #endif
 
@@ -150,7 +150,7 @@ typedef BID_UINT128 _Quad;
 ///////////////////////////////////////////////////////
 //  This section may move to fenv_support.h
 
-#if !defined(__FENV_H_INCLUDED) && !defined (_FENV_H) && !defined(_FENV_INCLUDED)          /* Otherwise we already defined fexcept_t type */
+#if !defined(__FENV_H_INCLUDED) && !defined (_FENV_H) && !defined(_FENV_INCLUDED) && !defined (_FENV_H_)          /* Otherwise we already defined fexcept_t type */
 #if defined(__ECL) || defined(__ECC)            /* Intel(R) Itanium(R) architecture */
 /* Default 64-bit Floating Point Status Register   */
 #if defined(__linux__)
