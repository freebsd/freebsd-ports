--- gcc/cccp.c.old	Wed May 19 15:10:39 2004
+++ gcc/cccp.c	Wed May 19 15:19:53 2004
@@ -24,6 +24,8 @@
 
 typedef unsigned char U_CHAR;
 
+#define HAS_STDARG_H
+
 #ifdef EMACS
 #define NO_SHORTNAMES
 #include "../src/config.h"
@@ -199,7 +201,7 @@
 # endif
 #endif
 
-#if defined (__STDC__) && defined (HAVE_VPRINTF)
+#if defined (__STDC__) && defined (HAVE_VPRINTF) || defined (HAS_STDARG_H)
 # include <stdarg.h>
 # define VA_START(va_list, var) va_start (va_list, var)
 # define PRINTF_ALIST(msg) char *msg, ...
@@ -8967,7 +8969,7 @@
 }
 
 static void
-#if defined (__STDC__) && defined (HAVE_VPRINTF)
+#if defined (__STDC__) && defined (HAVE_VPRINTF) || defined (HAS_STDARG_H)
 error_with_line (int line, PRINTF_ALIST (msg))
 #else
 error_with_line (line, PRINTF_ALIST (msg))
@@ -9007,7 +9009,7 @@
 }
 
 static void
-#if defined (__STDC__) && defined (HAVE_VPRINTF)
+#if defined (__STDC__) && defined (HAVE_VPRINTF) || defined (HAS_STDARG_H)
 warning_with_line (int line, PRINTF_ALIST (msg))
 #else
 warning_with_line (line, PRINTF_ALIST (msg))
@@ -9069,7 +9071,7 @@
 }
 
 void
-#if defined (__STDC__) && defined (HAVE_VPRINTF)
+#if defined (__STDC__) && defined (HAVE_VPRINTF) || defined (HAS_STDARG_H)
 pedwarn_with_line (int line, PRINTF_ALIST (msg))
 #else
 pedwarn_with_line (line, PRINTF_ALIST (msg))
@@ -9091,7 +9093,7 @@
    giving specified file name and line number, not current.  */
 
 static void
-#if defined (__STDC__) && defined (HAVE_VPRINTF)
+#if defined (__STDC__) && defined (HAVE_VPRINTF) || defined (HAS_STDARG_H)
 pedwarn_with_file_and_line (char *file, int line, PRINTF_ALIST (msg))
 #else
 pedwarn_with_file_and_line (file, line, PRINTF_ALIST (msg))
