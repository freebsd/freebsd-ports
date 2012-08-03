--- H/memalloc.h.orig	2012-07-29 14:44:42.000000000 -0500
+++ H/memalloc.h	2012-07-29 14:51:44.000000000 -0500
@@ -40,14 +40,15 @@
 #if defined(__WATCOMC__) || defined(__BORLANDC__) || defined(__OCC__)
 #define myalloca  alloca
 #include <malloc.h>
-#elif defined(__GNUC__) || defined(__TINYC__)
+#elif (defined(__GNUC__) || defined(__TINYC__)) && !defined(__FreeBSD__)
 #define myalloca  alloca
 #include <malloc.h>  /* added v2.07 */
 #elif defined(__PCC__)
 #define myalloca  _alloca
 #include <malloc.h>
 #else
-#define myalloca  _alloca
+#define myalloca  alloca
+#include <stdlib.h>
 #endif
 
 /* AsmAlloc() and AsmFree() are fast variants, which
