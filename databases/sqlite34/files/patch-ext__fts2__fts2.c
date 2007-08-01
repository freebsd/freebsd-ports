--- ext/fts2/fts2.c.orig	Fri Jun  8 12:31:37 2007
+++ ext/fts2/fts2.c	Fri Jun  8 12:32:16 2007
@@ -269,9 +269,6 @@
 #endif
 
 #include <assert.h>
-#if !defined(__APPLE__)
-#include <malloc.h>
-#endif
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
