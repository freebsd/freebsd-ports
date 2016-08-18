--- SP/code/qcommon/q_platform.h.orig	2015-12-26 14:21:49 UTC
+++ SP/code/qcommon/q_platform.h
@@ -35,11 +35,7 @@ Foundation, Inc., 51 Franklin St, Fifth 
 
 #else
 
-#if (defined _M_IX86 || defined __i386__) && !defined(C_ONLY)
-#define id386 1
-#else
 #define id386 0
-#endif
 
 #if (defined(powerc) || defined(powerpc) || defined(ppc) || \
 	defined(__ppc) || defined(__ppc__)) && !defined(C_ONLY)
@@ -229,8 +225,6 @@ Foundation, Inc., 51 Franklin St, Fifth 
 #ifdef __i386__
 #define ARCH_STRING "i386"
 #elif defined __amd64__
-#undef idx64
-#define idx64 1
 #define ARCH_STRING "amd64"
 #elif defined __axp__
 #define ARCH_STRING "alpha"
