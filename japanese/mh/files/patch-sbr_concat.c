--- sbr/concat.c.orig	1993-12-01 04:01:21 UTC
+++ sbr/concat.c
@@ -2,34 +2,40 @@
 
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
                    *sp;
     register unsigned   len;
-    register    va_list list;
+    va_list list;
 
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
