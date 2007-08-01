--- ext/fts2/fts2_porter.c.orig	Fri Jun  8 12:31:44 2007
+++ ext/fts2/fts2_porter.c	Fri Jun  8 12:32:21 2007
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
