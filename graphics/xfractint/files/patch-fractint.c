--- fractint.c.orig	Tue Sep  7 00:38:10 1999
+++ fractint.c	Sun Dec  7 12:15:08 2003
@@ -10,7 +10,7 @@
 #include <io.h>
 #include <stdarg.h>
 #else
-#include <varargs.h>
+#include <stdarg.h>
 #endif
 #include <ctype.h>
 
@@ -540,12 +540,7 @@
      timer(1,NULL,int width)            decoder
      timer(2)                           encoder
   */
-#ifndef XFRACT
 int timer(int timertype,int(*subrtn)(),...)
-#else
-int timer(va_alist)
-va_dcl
-#endif
 {
    va_list arg_marker;  /* variable arg list */
    char *timestring;
@@ -555,15 +550,7 @@
    int i;
    int do_bench;
 
-#ifndef XFRACT
    va_start(arg_marker,subrtn);
-#else
-   int timertype;
-   int (*subrtn)();
-   va_start(arg_marker);
-   timertype = va_arg(arg_marker, int);
-   subrtn = (int (*)())va_arg(arg_marker, int *);
-#endif
 
    do_bench = timerflag; /* record time? */
    if (timertype == 2)   /* encoder, record time only if debug=200 */
