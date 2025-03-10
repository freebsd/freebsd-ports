--- xcalc.c.orig
+++ xcalc.c
@@ -32,6 +32,7 @@
  *                  it's an option.
  */
 
+#include <errno.h>
 #include <stdio.h>
 #include <math.h>
 #include <signal.h>
@@ -43,8 +44,6 @@
 
 /* program icon */
 #include "icon"
-
-extern int errno;
 
 
 /* constants used for setting up the calculator.  changing them would 
