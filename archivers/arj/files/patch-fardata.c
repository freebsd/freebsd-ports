--- fardata.c.orig	2010-01-18 10:06:57.000000000 -0200
+++ fardata.c	2010-01-18 10:08:24.000000000 -0200
@@ -655,7 +655,7 @@
     num=va_arg(args, unsigned long);
    else if(qualifier=='h')
    {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (flags&SIGN)
      num=va_arg(args, int);             /* num=va_arg(args, short);      */
     else
