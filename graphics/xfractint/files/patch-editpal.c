--- editpal.c.orig	Tue Sep  7 00:38:10 1999
+++ editpal.c	Sun Dec  7 02:53:19 2003
@@ -114,11 +114,7 @@
 #endif
 
 #include <string.h>
-#ifndef XFRACT
 #include <stdarg.h>
-#else
-#include <varargs.h>
-#endif
 
 #ifdef __TURBOC__
 #   include <mem.h>   /* to get mem...() declarations */
@@ -410,31 +406,14 @@
    }
 
 
-#ifndef XFRACT
 static void displayf(int x, int y, int fg, int bg, char *format, ...)
-#else
-static void displayf(va_alist)
-va_dcl
-#endif
    {
    char buff[81];
    int  ctr;
 
    va_list arg_list;
 
-#ifndef XFRACT
    va_start(arg_list, format);
-#else
-   int x,y,fg,bg;
-   char *format;
-
-   va_start(arg_list);
-   x = va_arg(arg_list,int);
-   y = va_arg(arg_list,int);
-   fg = va_arg(arg_list,int);
-   bg = va_arg(arg_list,int);
-   format = va_arg(arg_list,char *);
-#endif
    vsprintf(buff, format, arg_list);
    va_end(arg_list);
 
