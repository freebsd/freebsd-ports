--- sail/misc.c.orig	Sat Jul 26 00:09:23 2003
+++ sail/misc.c	Sat Jul 26 00:09:38 2003
@@ -41,6 +41,7 @@
 
 #include "externs.h"
 #include "pathnames.h"
+#include "misc.h"
 
 #define distance(x,y) (abs(x) >= abs(y) ? abs(x) + abs(y)/2 : abs(y) + abs(x)/2)
 
