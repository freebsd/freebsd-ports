--- utils.c.orig	Fri Sep 12 18:01:20 2003
+++ utils.c	Fri Sep 12 22:21:05 2003
@@ -30,8 +30,7 @@
 #  include <poll.h>
 #endif
 #include <curses.h>
-#undef va_start			/* required with Red Hat's ncurses :-P */
-#include <varargs.h>
+#include <stdarg.h>
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/ioctl.h>						/* M001 */
@@ -75,16 +74,13 @@
 \***************************************************************************/
 
 /*VARARGS*/
-char *form (va_alist)
-  va_dcl
+char *form (const char *fmt_string, ...)
 {
   va_list pvar;
-  char *fmt_string;
   static char result[LINELEN];
   
-  va_start (pvar);
-  fmt_string = va_arg (pvar, char*);
-  (void) vsprintf (result, fmt_string, pvar);
+  va_start (pvar, fmt_string);
+  (void) vsnprintf (result, LINELEN, fmt_string, pvar);
   va_end (pvar);
   return (result);
 }
