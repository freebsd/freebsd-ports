
$FreeBSD$

--- src/list.c	2002/06/01 21:08:46	1.1
+++ src/list.c	2002/06/01 21:09:16
@@ -24,6 +24,7 @@
 
 #include "system.h"
 #include <quotearg.h>
+#include <langinfo.h>
 
 #include "common.h"
 
@@ -78,6 +79,10 @@
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
@@ -832,6 +837,7 @@
 char const *
 tartime (time_t t)
 {
+#if !defined(__FreeBSD__)
   static char buffer[max (UINTMAX_STRSIZE_BOUND + 1,
 			  INT_STRLEN_BOUND (int) + 16)];
   char *p;
@@ -870,6 +876,16 @@
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
