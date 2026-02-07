--- iprintf/isprintf.c.orig	2016-07-26 13:07:24 UTC
+++ iprintf/isprintf.c
@@ -8,13 +8,7 @@
 
 
 #include <stdio.h>
-#if defined(ANSI)
 # include	<stdarg.h>
-#elif defined(UNIX)
-# include	<varargs.h>
-#else
-  Error : varargs.h or stdarg.h is required to compile this.
-#endif	/* ANSI or UNIX */
 
 
 #if defined(ANSI)
@@ -49,47 +43,22 @@ i_sputn(dest, string, count, total_count
 }
     
 
-#if defined(ANSI)
 int
 isprintf(char *buf, char *format, ...)
-#elif defined(UNIX)
-int
-isprintf(buf, format, va_alist)
-	char	*buf;
-	char	*format;
-	va_dcl
-#endif	/* ANSI or UNIX */
 {
 	int		n;
 	va_list	args;
 
-#if defined(ANSI)
 	va_start (args, format);
-#elif defined(UNIX)
-	va_start(args);
-#endif	/* ANSI or UNIX */
 	buf[n = idoprnt(i_sputn, buf, format, args)] = '\0';
 	return (n);
 }
     
 
-#if defined(ANSI)
 int
 ivsprintf(char *buf, char *format, va_list args)
-#elif defined(UNIX)
-int
-ivsprintf(buf, format, va_alist)
-	char	*buf;
-	char	*format;
-	va_dcl
-#endif	/* ANSI or UNIX */
 {
 	int		n;
-#if defined(UNIX)
-	va_list	args;
-
-	va_start(args);
-#endif	/* UNIX */
 	buf[n = idoprnt(i_sputn, buf, format, args)] = '\0';
 	return (n);
 }
