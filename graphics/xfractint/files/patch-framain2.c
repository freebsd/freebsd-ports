--- framain2.c.orig	Tue Sep  7 00:38:10 1999
+++ framain2.c	Sun Dec  7 11:37:30 2003
@@ -1,10 +1,8 @@
 #include <string.h>
 #include <time.h>
+#include <stdarg.h>
 #ifndef XFRACT
 #include <io.h>
-#include <stdarg.h>
-#else
-#include <varargs.h>
 #endif
 #include <ctype.h>
   /* see Fractint.c for a description of the "include"  hierarchy */
