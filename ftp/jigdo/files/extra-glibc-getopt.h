--- src/glibc-getopt.h.orig	Fri Dec  6 08:24:36 2002
+++ src/glibc-getopt.h	Fri Dec  6 08:29:58 2002
@@ -37,12 +37,11 @@
 #  define ELIDE_CODE
 # endif
 #endif
+#define ELIDE_CODE
 #ifndef ELIDE_CODE
 #  define opterr my_opterr
 #  define optind my_optind
 #  define optopt my_optopt
-#endif
-
 
 #ifdef  __cplusplus
 extern "C" {
@@ -186,5 +185,6 @@
 
 /* Make sure we later can get all the definitions and declarations.  */
 #undef __need_getopt
+#endif /* ELIDE_CODE */
 
 #endif /* getopt.h */
