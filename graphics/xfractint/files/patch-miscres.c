--- miscres.c.orig	Tue Sep  7 00:38:10 1999
+++ miscres.c	Sun Dec  7 10:48:38 2003
@@ -5,12 +5,12 @@
 #include <string.h>
 #include <ctype.h>
 #include <time.h>
+#include <stdarg.h>
+#ifndef BIG_ANSI_C
 #include <malloc.h>
+#endif
 #ifndef XFRACT
-#include <stdarg.h>
 #include <io.h>
-#else
-#include <varargs.h>
 #endif
 /*#ifdef __TURBOC__
 #include <dir.h>
