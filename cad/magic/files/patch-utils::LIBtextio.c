--- utils/LIBtextio.c.orig	Tue Dec  9 16:52:38 2003
+++ utils/LIBtextio.c	Tue Dec  9 16:52:53 2003
@@ -19,10 +19,10 @@
 
 #ifndef	lint
 static char rcsid[] = "$Header: /ufs/repository/magic/utils/LIBtextio.c,v 1.1.1.1 2000/03/29 18:35:16 rajit Exp $";
-#endif	not lint
+#endif
 
 #include <stdio.h>
-#include <varargs.h>
+#include <stdarg.h>
 
 /*
  * ----------------------------------------------------------------------------
@@ -65,15 +65,13 @@
  */
 
     /*VARARGS*/
-TxError(fmt, va_alist)
-    char *fmt;
-    va_dcl
+TxError(char *fmt, ... )
 {
     va_list ap;
  
     (void) fflush(stdout);
     (void) fflush(stderr);
-    va_start(ap);
+    va_start(ap, fmt);
     vfprintf(stderr, fmt, ap);
     va_end(ap);
     (void) fflush(stderr);
@@ -96,15 +94,13 @@
  */
 
     /*VARARGS*/
-TxPrintf(fmt, va_alist)
-    char *fmt;
-    va_dcl
+TxPrintf(char *fmt, ... )
 {
     va_list ap;
  
     (void) fflush(stderr);
     (void) fflush(stdout);
-    va_start(ap);
+    va_start(ap, fmt);
     vfprintf(stdout, fmt, ap);
     va_end(ap);
     (void) fflush(stdout);
