--- tech/tech.c.orig	Tue Dec  9 16:40:02 2003
+++ tech/tech.c	Tue Dec  9 16:40:18 2003
@@ -18,7 +18,7 @@
 
 #ifndef lint
 static char rcsid[] = "$Header: /ufs/repository/magic/tech/tech.c,v 1.3 2001/01/12 22:13:25 jsolomon Exp $";
-#endif  not lint
+#endif
 
 #include <stdio.h>
 #include <ctype.h>
@@ -31,8 +31,8 @@
 #include "utils/malloc.h"
 
 #ifndef NO_VARARGS
-#include <varargs.h>
-#endif  NO_VARARGS
+#include <stdarg.h>
+#endif
 
 global char *TechDefault = NULL;
 
@@ -415,19 +415,16 @@
  /*VARARGS0*/
 
 void
-TechError(va_alist)
-va_dcl
+TechError(char *fmt, ...)
 {
     va_list args;
-    char *fmt;
 
     TechPrintLine();
-    va_start(args);
-    fmt = va_arg(args, char *);
+    va_start(args, fmt);
     (void) GrVfprintf(stderr, fmt, args);
     va_end(args);
 }
-#else	NO_VARARGS
+#else
 
  /*VARARGS0*/
 
@@ -440,7 +437,7 @@
     (void) GrFprintf(stderr, format, a1, a2, a3, a4, a5, a6, a7, a8, a9, 
 		     a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20);
 }
-#endif	NO_VARARGS
+#endif
 
 /* ================== Functions local to this module ================== */
 
