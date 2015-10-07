--- include/mitsuba/core/constants.h.orig	2015-07-15 10:37:38 UTC
+++ include/mitsuba/core/constants.h
@@ -43,10 +43,6 @@
 #undef M_PI
 #endif
 
-#ifdef INFINITY
-#undef INFINITY
-#endif
-
 #if defined(__WINDOWS__)
 #define ONE_MINUS_EPS_FLT 0.999999940395355225f
 #define ONE_MINUS_EPS_DBL 0.999999999999999888
