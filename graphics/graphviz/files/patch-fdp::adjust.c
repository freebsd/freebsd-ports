--- fdp/adjust.c.orig	Wed May  3 22:28:23 2000
+++ fdp/adjust.c	Wed Nov  7 17:46:43 2001
@@ -1,5 +1,7 @@
 /* adjust.c
  */
+#include <math.h>
+#include <assert.h>
 #include "adjust.h"
 #include "grid.h"
 #include "structs.h"
@@ -7,8 +9,6 @@
 #include "options.h"
 #include "component.h"
 #include "macros.h"
-#include <math.h>
-#include <assert.h>
 
 static void
 doRep (fdp_data* p, fdp_data* q, double xdelta, double ydelta, double dist2)
