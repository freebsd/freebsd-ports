--- ext/fts1/fts1_porter.c.orig	Sun Oct  1 13:01:13 2006
+++ ext/fts1/fts1_porter.c	Sun Dec  3 14:45:17 2006
@@ -26,11 +26,7 @@
 
 
 #include <assert.h>
-#if !defined(__APPLE__)
-#include <malloc.h>
-#else
 #include <stdlib.h>
-#endif
 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
