--- fardata.c.orig	2010-01-18 10:06:57.000000000 -0200
+++ fardata.c	2010-01-18 10:08:24.000000000 -0200
@@ -190,7 +190,7 @@ int msg_sprintf(char *str, FMSG *fmt, ..
 
 /* Length-limited strlen() */
 
-static int strnlen(const char FAR *s, int count)
+static int _strnlen(const char FAR *s, int count)
 {
  const char FAR *sc;
 
@@ -569,7 +569,7 @@ int vcprintf(int ccode, FMSG *fmt, va_li
     if(!s)
      s="(null)";
 #endif
-    len=strnlen(s, precision);
+    len=_strnlen(s, precision);
     if(!(flags&LEFT))
     {
      while(len<field_width--)
@@ -655,7 +655,7 @@ int vcprintf(int ccode, FMSG *fmt, va_li
     num=va_arg(args, unsigned long);
    else if(qualifier=='h')
    {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (flags&SIGN)
      num=va_arg(args, int);             /* num=va_arg(args, short);      */
     else
