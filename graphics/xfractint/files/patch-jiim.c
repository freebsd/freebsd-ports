--- jiim.c.orig	Tue Sep  7 00:38:10 1999
+++ jiim.c	Sun Dec  7 11:38:56 2003
@@ -39,12 +39,7 @@
  */
 
 #include <string.h>
-
-#ifndef XFRACT
 #include <stdarg.h>
-#else
-#include <varargs.h>
-#endif
 
 #ifdef __TURBOC__
 #   include <mem.h>   /* to get mem...() declarations */
