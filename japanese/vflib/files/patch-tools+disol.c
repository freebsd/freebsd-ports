--- tools/disol.c.orig	Thu Nov  6 15:59:00 2003
+++ tools/disol.c	Thu Nov  6 16:01:39 2003
@@ -33,7 +33,11 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#if defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ > 2 || __GNUC__ >= 4)
+#include <stdarg.h>
+#else 
 #include <varargs.h>
+#endif
 #include "../src/VF.h"
 
 #define CommentLine printf
