--- ext/fts1/fts1.c.orig	Sun Oct  8 06:16:32 2006
+++ ext/fts1/fts1.c	Sun Dec  3 14:44:46 2006
@@ -19,11 +19,7 @@
 #endif
 
 #include <assert.h>
-#if !defined(__APPLE__)
-#include <malloc.h>
-#else
 #include <stdlib.h>
-#endif
 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
