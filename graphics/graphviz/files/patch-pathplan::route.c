--- pathplan/route.c.orig	Sun Oct 15 11:13:58 2000
+++ pathplan/route.c	Thu Nov  8 17:12:41 2001
@@ -11,7 +11,9 @@
 
 #include <stdlib.h>
 #include <stdio.h>
+#ifndef __STDC__
 #include <malloc.h>
+#endif
 #include <math.h>
 #include "pathplan.h"
 #include "solvers.h"
