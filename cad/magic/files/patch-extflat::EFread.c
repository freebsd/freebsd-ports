--- extflat/EFread.c.orig	Tue Dec  9 16:24:57 2003
+++ extflat/EFread.c	Tue Dec  9 16:25:13 2003
@@ -19,12 +19,12 @@
 
 #ifndef lint
 static char rcsid[] = "$Header: /ufs/repository/magic/extflat/EFread.c,v 1.2 2001/01/12 22:12:35 jsolomon Exp $";
-#endif  not lint
+#endif
 
 #include <stdio.h>
 #include <ctype.h>
 #include <stdlib.h>
-#include <varargs.h>
+#include <stdarg.h>
 #include "misc/magic.h"
 #include "utils/geometry.h"
 #include "utils/hash.h"
@@ -534,14 +534,12 @@
  */
 
     /*VARARGS1*/
-efReadError(fmt, va_alist)
-    char *fmt;
-    va_dcl
+efReadError(char *fmt, ... )
 {
     va_list args;
 
     (void) printf("%s, line %d: ", efReadFileName, efReadLineNum);
-    va_start(args);
+    va_start(args, fmt);
     vfprintf(stdout, fmt, args);
     va_end(args);
     (void) fflush(stdout);
