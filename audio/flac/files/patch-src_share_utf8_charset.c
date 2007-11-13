
$FreeBSD$

--- src/share/utf8/charset.c.orig
+++ src/share/utf8/charset.c
@@ -35,6 +35,7 @@
 
 #include <stdlib.h>
 
+#include "share/alloc.h"
 #include "charset.h"
 
 #include "charmaps.h"
@@ -492,7 +493,7 @@
   if (!charset1 || !charset2 )
     return -1;
 
-  tobuf = (char *)malloc(fromlen * charset2->max + 1);
+  tobuf = (char *)safe_malloc_mul2add_(fromlen, /*times*/charset2->max, /*+*/1);
   if (!tobuf)
     return -2;
 
