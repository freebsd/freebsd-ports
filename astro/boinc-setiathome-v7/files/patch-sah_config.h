--- sah_config.h.orig	2012-09-19 00:45:14.000000000 +0200
+++ sah_config.h	2013-07-19 18:35:22.000000000 +0200
@@ -21,7 +21,7 @@
 #define AVX_MASKSTORE_TYPECAST(x) reinterpret_cast<__m256i>(x)
 
 /* Define to 1 to build a graphical application */
-#define BOINC_APP_GRAPHICS 1
+/* #undef BOINC_APP_GRAPHICS */
 
 /* Define to a string identifying your compiler */
 #define COMPILER_STRING "g++ (GCC) 4.4.6 20110731 (Red Hat 4.4.6-3)"
