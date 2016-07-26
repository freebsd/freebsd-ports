--- sah_config.h.orig	2012-09-18 22:45:14 UTC
+++ sah_config.h
@@ -21,7 +21,7 @@
 #define AVX_MASKSTORE_TYPECAST(x) reinterpret_cast<__m256i>(x)
 
 /* Define to 1 to build a graphical application */
-#define BOINC_APP_GRAPHICS 1
+/* #undef BOINC_APP_GRAPHICS */
 
 /* Define to a string identifying your compiler */
 #define COMPILER_STRING "g++ (GCC) 4.4.6 20110731 (Red Hat 4.4.6-3)"
