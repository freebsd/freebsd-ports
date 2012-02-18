--- opennurbs_system.h.orig	2012-01-20 20:28:51.000000000 +0100
+++ opennurbs_system.h	2012-01-20 20:28:32.000000000 +0100
@@ -217,7 +217,6 @@
 #if defined(ON_COMPILER_XCODE)
 #include <malloc/malloc.h>
 #else
-#include <malloc.h>
 #endif
 #include <string.h>
 #include <math.h>
@@ -299,7 +298,6 @@
 /* 16-bit wide character ("UNICODE") */
 
 #if !defined(_WCHAR_T)
-typedef unsigned short wchar_t;
 #endif
 
 #define _WCHAR_T_DEFINED
