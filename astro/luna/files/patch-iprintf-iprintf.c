--- iprintf/iprintf.c.orig	Thu Apr 23 16:23:14 1992
+++ iprintf/iprintf.c	Sat Nov 22 04:11:33 2003
@@ -13,7 +13,7 @@
 #if defined(ANSI)
 # include	<stdarg.h>
 #elif defined(UNIX)
-# include	<varargs.h>
+# include	<stdarg.h>
 #else
   Error : varargs.h or stdarg.h is required to compile this.
 #endif	/* ANSI or UNIX */
@@ -52,44 +52,21 @@
 }
 
 
-#if defined(ANSI)
 int
 iprintf(char *format, ...)
-#elif defined(UNIX)
-int
-iprintf(format, va_alist)
-	char	*format;
-	va_dcl
-#endif	/* ANSI or UNIX */
 {
 	va_list args;
 
-#if defined(ANSI)
 	va_start (args, format);
-#elif defined(UNIX)
-	va_start(args);
-#endif	/* ANSI or UNIX */
 	return (ivprintf(format, args));
 }
 
 
-#if defined(ANSI)
 int
 ifprintf(FILE *stream, char *format, ...)
-#elif defined(UNIX)
-int
-ifprintf(stream, format, va_alist)
-	FILE	*stream;
-	char	*format;
-	va_dcl
-#endif	/* UNIX */
 {
 	va_list args;
 
-#if defined(ANSI)
 	va_start (args, format);
-#elif defined(UNIX)
-	va_start(args);
-#endif	/* ANSI or UNIX */
 	return (ivfprintf(stream, format, args));
 }
