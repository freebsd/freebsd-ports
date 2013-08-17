--- src/pyodbc.h.orig	2012-01-13 13:10:48.000000000 -0600
+++ src/pyodbc.h	2012-12-06 10:21:36.527165345 -0600
@@ -76,7 +76,9 @@
 #include <stdarg.h>
 
 #if defined(__SUNPRO_CC) || defined(__SUNPRO_C) || (defined(__GNUC__) && !defined(__MINGW32__))
+#ifndef __FreeBSD__
 #include <alloca.h>
+#endif
 #define CDECL cdecl
 #define min(X,Y) ((X) < (Y) ? (X) : (Y))
 #define max(X,Y) ((X) > (Y) ? (X) : (Y))
