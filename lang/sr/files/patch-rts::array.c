--- rts/array.c.orig	Sat Dec 13 19:38:54 2003
+++ rts/array.c	Sat Dec 13 19:52:13 2003
@@ -1,7 +1,7 @@
 /*  array.c -- runtime support of arrays  */
 
 #include "rts.h"
-#include <varargs.h>
+#include <stdarg.h>
 
 
 static void slices ();
@@ -22,13 +22,10 @@
  */
 /*VARARGS*/
 Array *
-sr_init_array (va_alist)
-va_dcl
+sr_init_array (char *locn, Array *addr, ...)
 {
     va_list ap;
-    char *locn;
     int ndim, elemsize, alcsize, i, n;
-    Array *addr;
     Dim *d;
     Ptr p, q, initvalue;
     int *lb, *ub, la[MAX_DIMENS], ua[MAX_DIMENS], size[MAX_DIMENS+1];
@@ -39,9 +36,7 @@
     /*
      *  Calculate the size of each dimension.
      */
-    va_start (ap);
-    locn = va_arg (ap, char *);
-    addr = va_arg (ap, Array *);
+    va_start (ap, addr);
     elemsize = va_arg (ap, int);
     initvalue = va_arg (ap, Ptr);
     ndim = va_arg (ap, int);
@@ -251,11 +246,9 @@
 
 /*VARARGS*/
 Ptr
-sr_slice (va_alist)
-va_dcl
+sr_slice (char *locn, ...)
 {
     va_list ap;
-    char *locn;
     Array *a1, *a2;
     int elemsize, nbounds;
     int adim, lb[MAX_DIMENS], ub[MAX_DIMENS];	/* array dims*/
@@ -266,8 +259,7 @@
     sr_check_stk (CUR_STACK);
 
     /* get fixed arguments */
-    va_start (ap);
-    locn = va_arg (ap, char *);		/* SR source code location */
+    va_start (ap, locn);
     a1 = va_arg (ap, Array *);		/* contiguous array */
     a2 = va_arg (ap, Array *);		/* sliced array */
     elemsize = va_arg (ap, int);	/* array element size */
