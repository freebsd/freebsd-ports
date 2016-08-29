--- include/Inventor/C/base/math-undefs.h.orig	2016-08-29 01:17:19 UTC
+++ include/Inventor/C/base/math-undefs.h
@@ -40,6 +40,8 @@
   work as intended.  20070518 larsa
 */
 
+#ifndef __clang__
+
 #undef cosf
 #define cosf(x) NO_SINGLEPREC /* whatever that'll give us a compile error... */
 #undef sinf
@@ -59,6 +61,9 @@
 #undef atan2f
 #define atan2f(x) NO_SINGLEPREC
 
+#endif // !__clang__
+
+
 /* *********************************************************************** */
 
 #endif // !COIN_MATH_UNDEFS_H
