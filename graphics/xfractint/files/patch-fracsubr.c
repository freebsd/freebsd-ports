--- fracsubr.c.orig	Tue Sep  7 00:38:10 1999
+++ fracsubr.c	Sun Dec  7 11:55:41 2003
@@ -4,11 +4,9 @@
 */
 
 #ifndef XFRACT
-#include <stdarg.h>
 #include <sys/timeb.h>
-#else
-#include <varargs.h>
 #endif
+#include <stdarg.h>
 #include <sys/types.h>
 #include <time.h>
   /* see Fractint.c for a description of the "include"  hierarchy */
@@ -1050,27 +1048,14 @@
 
    */
 
-#ifndef XFRACT
 int put_resume(int len, ...)
-#else
-int put_resume(va_alist)
-va_dcl
-#endif
 {
    va_list arg_marker;  /* variable arg list */
    BYTE *source_ptr;
-#ifdef XFRACT
-   int len;
-#endif
 
    if (resume_info == 0)
       return(-1);
-#ifndef XFRACT
    va_start(arg_marker,len);
-#else
-   va_start(arg_marker);
-   len = va_arg(arg_marker,int);
-#endif
    while (len)
    {
       source_ptr = (BYTE *)va_arg(arg_marker,char *);
@@ -1101,27 +1086,14 @@
    return(0);
 }
 
-#ifndef XFRACT
 int get_resume(int len, ...)
-#else
-int get_resume(va_alist)
-va_dcl
-#endif
 {
    va_list arg_marker;  /* variable arg list */
    BYTE *dest_ptr;
-#ifdef XFRACT
-   int len;
-#endif
 
    if (resume_info == 0)
       return(-1);
-#ifndef XFRACT
    va_start(arg_marker,len);
-#else
-   va_start(arg_marker);
-   len = va_arg(arg_marker,int);
-#endif
    while (len)
    {
       dest_ptr = (BYTE *)va_arg(arg_marker,char *);
