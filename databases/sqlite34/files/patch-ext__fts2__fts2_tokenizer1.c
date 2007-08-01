--- ext/fts2/fts2_tokenizer1.c.orig	Fri Jun  8 12:31:51 2007
+++ ext/fts2/fts2_tokenizer1.c	Fri Jun  8 12:32:26 2007
@@ -18,11 +18,7 @@
 
 
 #include <assert.h>
-#if !defined(__APPLE__)
-#include <malloc.h>
-#else
 #include <stdlib.h>
-#endif
 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
