
$FreeBSD$

--- lib/qprintf.c.orig	Fri Feb  1 19:15:32 2002
+++ lib/qprintf.c	Fri Feb  1 19:15:49 2002
@@ -34,7 +34,8 @@
 * Same as fprintf to stderr but with optional print.			     *
 *****************************************************************************/
 #ifdef HAVE_VARARGS_H
-void GifQprintf(int va_alist)
+void GifQprintf(va_alist)
+va_dcl
 {
     char *Format, Line[128];
     va_list ArgPtr;
