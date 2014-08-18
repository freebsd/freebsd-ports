--- spice3f5/common/src/include/util.h.orig	1994-01-29 19:14:24 UTC
+++ spice3f5/common/src/include/util.h
@@ -6,6 +6,10 @@ Author: 1985 Thomas L. Quarles
 #ifndef UTIL
 #define UTIL
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 /* #define MALLOC(x) calloc(1,(unsigned)(x)) */
 #define MALLOC(x) tmalloc((unsigned)(x))
 #define FREE(x) {if (x) {free((char *)(x));(x) = 0;}}
@@ -18,8 +22,10 @@ Author: 1985 Thomas L. Quarles
 #include <stdlib.h>
 #endif
 #else
+/*
 extern char *malloc();
 extern char *calloc();
+*/
 extern char *realloc();
 extern void free();
 #endif
@@ -44,8 +50,10 @@ double fabs();
 #endif
 
 /* XXX Move these into the above ifdef someday */
+#if !(defined(BSD) && (BSD >= 199306))
 #define MIN(a,b) ((a) < (b) ? (a) : (b))
 #define MAX(a,b) ((a) > (b) ? (a) : (b))
+#endif
 #define SIGN(a,b) ( b >= 0 ? (a >= 0 ? a : - a) : (a >= 0 ? - a : a))
 
 #define ABORT() fflush(stderr);fflush(stdout);abort();
