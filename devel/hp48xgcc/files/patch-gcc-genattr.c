--- ../gcc-2.7.2/genattr.c.orig	1995-06-15 11:38:53 UTC
+++ ../gcc-2.7.2/genattr.c
@@ -20,6 +20,7 @@ the Free Software Foundation, 59 Temple Place - Suite 
 Boston, MA 02111-1307, USA.  */
 
 
+#include <stdarg.h>
 #include <stdio.h>
 #include "hconfig.h"
 #include "rtl.h"
@@ -35,7 +36,7 @@ extern void free PROTO((void *));
 extern rtx read_rtx PROTO((FILE *));
 
 char *xmalloc PROTO((unsigned));
-static void fatal ();
+static void fatal PVPROTO ((const char *, ...));
 void fancy_abort PROTO((void));
 
 /* A range of values.  */
@@ -214,11 +215,15 @@ xrealloc (ptr, size)
 }
 
 static void
-fatal (s, a1, a2)
-     char *s;
+fatal VPROTO ((const char *format, ...))
 {
+  va_list ap;
+
+  VA_START (ap, format);
+
   fprintf (stderr, "genattr: ");
-  fprintf (stderr, s, a1, a2);
+  vfprintf (stderr, format, ap);
+  va_end (ap);
   fprintf (stderr, "\n");
   exit (FATAL_EXIT_CODE);
 }
