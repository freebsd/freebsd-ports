--- ext/fts1/fts1_tokenizer1.c.orig	Sat Sep 30 08:57:33 2006
+++ ext/fts1/fts1_tokenizer1.c	Sun Dec  3 14:45:56 2006
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
