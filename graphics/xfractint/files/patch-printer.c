--- printer.c.orig	Tue Sep  7 00:38:10 1999
+++ printer.c	Sun Dec  7 11:42:07 2003
@@ -86,12 +86,10 @@
 #include <fcntl.h>
 #include <sys/types.h>
 #include <errno.h>
+#include <stdarg.h>
 
 #ifndef XFRACT
 #include <conio.h>
-#include <stdarg.h>
-#else
-#include <varargs.h>
 #endif
 
 #include <string.h>
@@ -136,11 +134,7 @@
 
 /********      PROTOTYPES     ********/
 
-#ifndef XFRACT
 static void Printer_printf(char far *fmt,...);
-#else
-static void Printer_printf();
-#endif
 static int  _fastcall printer(int c);
 static void _fastcall print_title(int,int,char *);
 static void printer_reset(void);
@@ -1335,25 +1329,14 @@
 
 /* This function prints a string to the the printer with BIOS calls. */
 
-#ifndef XFRACT
 static void Printer_printf(char far *fmt,...)
-#else
-static void Printer_printf(va_alist)
-va_dcl
-#endif
 {
 int i;
 char s[500];
 int x=0;
 va_list arg;
 
-#ifndef XFRACT
 va_start(arg,fmt);
-#else
-char far *fmt;
-va_start(arg);
-fmt = va_arg(arg,char far *);
-#endif
 
 {
    /* copy far to near string */
