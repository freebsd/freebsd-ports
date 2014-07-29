--- rts/math.c.orig	Sat Dec 13 19:38:54 2003
+++ rts/math.c	Sat Dec 13 19:43:26 2003
@@ -1,6 +1,6 @@
 /*  math.c -- runtime support of arithmetic and math builtins  */
 
-#include <varargs.h>
+#include <stdarg.h>
 #include "rts.h"
 
 
@@ -162,14 +162,12 @@
  */
 /*VARARGS*/
 int
-sr_imax (va_alist)
-va_dcl
+sr_imax (int n, ...)
 {
     va_list ap;
-    int n, r, v;
+    int r, v;
 
-    va_start (ap);
-    n = va_arg (ap, int);
+    va_start (ap, n);
     if (n <= 0)
 	sr_malf ("no args to sr_imax");
 
@@ -193,14 +191,12 @@
  */
 /*VARARGS*/
 int
-sr_imin (va_alist)
-va_dcl
+sr_imin (int n, ...)
 {
     va_list ap;
-    int n, r, v;
+    int r, v;
 
-    va_start (ap);
-    n = va_arg (ap, int);
+    va_start (ap, n);
     if (n <= 0)
 	sr_malf ("no args to sr_imin");
 
@@ -222,15 +218,12 @@
  */
 /*VARARGS*/
 Real
-sr_rmax (va_alist)
-va_dcl
+sr_rmax (int n, ...)
 {
     va_list ap;
-    int n;
     Real r, v;
 
-    va_start (ap);
-    n = va_arg (ap, int);
+    va_start (ap, n);
     if (n <= 0)
 	sr_malf ("no args to sr_rmax");
 
@@ -254,15 +247,12 @@
  */
 /*VARARGS*/
 Real
-sr_rmin (va_alist)
-va_dcl
+sr_rmin (int n, ...)
 {
     va_list ap;
-    int n;
     Real r, v;
 
-    va_start (ap);
-    n = va_arg (ap, int);
+    va_start (ap, n);
     if (n <= 0)
 	sr_malf ("no args to sr_rmin");
 
