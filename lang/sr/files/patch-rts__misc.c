--- rts/misc.c.orig	Sat Dec 13 19:38:54 2003
+++ rts/misc.c	Sat Dec 13 19:59:34 2003
@@ -1,6 +1,6 @@
 /*  misc.c -- miscellaneous routines supporting the generated code  */
 
-#include <varargs.h>
+#include <stdarg.h>
 #include "rts.h"
 
 
@@ -15,8 +15,7 @@
  */
 /*VARARGS*/
 Ptr
-sr_cat (va_alist)
-va_dcl
+sr_cat (String *a, ...)
 {
     va_list ap;
     String *s, *t;
@@ -24,7 +23,12 @@
     char *p;
 
     n = 0;					/* total the string lengths */
-    va_start (ap);
+    va_start (ap, a);
+    if ((int) a & 1)
+        n++;
+    else
+       n += s->length;
+
     while ((s = va_arg (ap, String *)) != NULL)
 	if ((int) s & 1)
 	    n++;				/* char argument */
@@ -37,7 +41,14 @@
     t->length = n;
 
     p = DATA (t);
-    va_start (ap);
+    va_start (ap, a);
+    if ((int) a & 1) {
+        *p++ = (int) a >> 2;
+    } else {
+        memcpy (p, DATA (a), a->length);
+        p += a->length;
+    }
+
     while ((s = va_arg (ap, String *)) != NULL) {   /* for each input string: */
 	if ((int) s & 1) {
 	    *p++ = (int) s >> 2;		    /* copy in char argument */
