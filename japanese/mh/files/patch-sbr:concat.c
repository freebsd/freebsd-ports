Index: sbr/concat.c
diff -u sbr/concat.c.orig sbr/concat.c
--- sbr/concat.c.orig	Wed Dec  1 13:01:21 1993
+++ sbr/concat.c	Fri Jul 18 14:42:47 2003
@@ -2,13 +2,12 @@
 
 #include "../h/mh.h"
 #include <stdio.h>
-#include <varargs.h>
+#include <stdarg.h>
 
 
 /* VARARGS */
 
-char   *concat (va_alist)
-va_dcl
+char   *concat (char *first, ...)
 {
     register char  *cp,
                    *dp,
@@ -17,19 +16,26 @@
     register    va_list list;
 
     len = 1;
-    va_start (list); 
-    while (cp = va_arg (list, char *))
-	len += strlen (cp);
-    va_end (list);
+    if (first) {
+	    len += strlen (first);
+	    va_start (list, first);
+	    while (cp = va_arg (list, char *))
+		    len += strlen (cp);
+	    va_end (list);
+    }
 
     dp = sp = malloc (len);
     if (dp == NULL)
 	adios (NULLCP, "unable to allocate string storage");
 
-    va_start (list); 
-    while (cp = va_arg (list, char *))
-	sp = copy (cp, sp);
-    va_end (list);
+    *sp = '\0';
+    if (first) {
+	    sp = copy (first, sp);
+	    va_start (list, first);
+	    while (cp = va_arg (list, char *))
+		    sp = copy (cp, sp);
+	    va_end (list);
+    }
 
     return dp;
 }
