--- hc.c.orig	Tue Sep  7 00:38:10 1999
+++ hc.c	Sun Dec  7 12:16:31 2003
@@ -56,7 +56,7 @@
 #include <io.h>
 #include <stdarg.h>
 #else
-#include <varargs.h>
+#include <stdarg.h>
 #define strupr strlwr
 #endif
 #include <fcntl.h>
@@ -295,24 +295,11 @@
    }
 
 
-#ifndef XFRACT
 void fatal(int diff, char *format, ...)
-#else
-void fatal(va_alist)
-    va_dcl
-#endif
    {
    va_list arg;
 
-#ifndef XFRACT
    va_start(arg, format);
-#else
-   int diff;
-   char *format;
-   va_start(arg);
-   diff = va_arg(arg,int);
-   format = va_arg(arg,char *);
-#endif
 
    print_msg("Fatal", srcline-diff, format, arg);
    va_end(arg);
@@ -324,24 +311,11 @@
    }
 
 
-#ifndef XFRACT
 void error(int diff, char *format, ...)
-#else
-void error(va_alist)
-    va_dcl
-#endif
    {
    va_list arg;
 
-#ifndef XFRACT
    va_start(arg, format);
-#else
-   int diff;
-   char *format;
-   va_start(arg);
-   diff = va_arg(arg,int);
-   format = va_arg(arg,char *);
-#endif
    print_msg("Error", srcline-diff, format, arg);
    va_end(arg);
 
@@ -350,23 +324,10 @@
    }
 
 
-#ifndef XFRACT
 void warn(int diff, char *format, ...)
-#else
-void warn(va_alist)
-   va_dcl
-#endif
    {
    va_list arg;
-#ifndef XFRACT
    va_start(arg, format);
-#else
-   int diff;
-   char *format;
-   va_start(arg);
-   diff = va_arg(arg, int);
-   format = va_arg(arg, char *);
-#endif
    print_msg("Warning", srcline-diff, format, arg);
    va_end(arg);
 
@@ -375,47 +336,22 @@
    }
 
 
-#ifndef XFRACT
 void notice(char *format, ...)
-#else
-void notice(va_alist)
-    va_dcl
-#endif
    {
    va_list arg;
-#ifndef XFRACT
    va_start(arg, format);
-#else
-   char *format;
-
-   va_start(arg);
-   format = va_arg(arg,char *);
-#endif
    print_msg("Note", srcline, format, arg);
    va_end(arg);
    }
 
 
-#ifndef XFRACT
 void msg(char *format, ...)
-#else
-void msg(va_alist)
-va_dcl
-#endif
    {
    va_list arg;
-#ifdef XFRACT
-   char *format;
-#endif
 
    if (quiet_mode)
       return;
-#ifndef XFRACT
    va_start(arg, format);
-#else
-   va_start(arg);
-   format = va_arg(arg,char *);
-#endif
    print_msg(NULL, 0, format, arg);
    va_end(arg);
    }
