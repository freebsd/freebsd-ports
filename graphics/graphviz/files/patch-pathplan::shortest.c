--- pathplan/shortest.c.orig	Tue Apr 18 05:56:48 2000
+++ pathplan/shortest.c	Thu Nov  8 17:13:03 2001
@@ -11,7 +11,9 @@
 
 #include <stdlib.h>
 #include <stdio.h>
+#ifndef __STDC__
 #include <malloc.h>
+#endif
 #include <limits.h>
 #include <math.h>
 #include "pathplan.h"
