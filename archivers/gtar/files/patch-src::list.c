
$FreeBSD$

--- src/list.c.orig	Wed Sep 26 23:05:04 2001
+++ src/list.c	Tue Jun  4 15:05:15 2002
@@ -24,6 +24,9 @@
 
 #include "system.h"
 #include <quotearg.h>
+#ifdef HAVE_LANGINFO_CODESET
+#include <langinfo.h>
+#endif
 
 #include "common.h"
 
@@ -78,6 +81,10 @@
     {
       prev_status = status;
       status = read_header (0);
+      /* check if the namelist got emptied during the course of reading */
+      /* the tape, if so stop by setting status to EOF */
+      if (namelist_freed)
+        status = HEADER_END_OF_FILE;
       switch (status)
 	{
 	case HEADER_STILL_UNREAD:
@@ -832,6 +839,7 @@
 char const *
 tartime (time_t t)
 {
+#if !defined(__FreeBSD__) || !defined(HAVE_LANGINFO_CODESET)
   static char buffer[max (UINTMAX_STRSIZE_BOUND + 1,
 			  INT_STRLEN_BOUND (int) + 16)];
   char *p;
@@ -870,6 +878,16 @@
   while (buffer + sizeof buffer - 19 - 1 < p)
     *--p = ' ';
   return p;
+#else /* __FreeBSD__ */
+  static char buffer[80];
+  static int d_first = -1;
+
+  if (d_first < 0)
+    d_first = (*nl_langinfo(D_MD_ORDER) == 'd');
+  strftime(buffer, sizeof(buffer), d_first ? "%e %b %R %Y" : "%b %e %R %Y",
+           localtime(&t));
+  return buffer;
+#endif /* __FreeBSD__ */
 }
 
 /* Actually print it.
