--- incr/routem.c.orig	Tue Apr 18 05:55:32 2000
+++ incr/routem.c	Wed Nov  7 17:49:35 2001
@@ -1,8 +1,8 @@
+#include <stdio.h>	/* temporary for debugging */
+#include <math.h>
 #include <engine.h>
 #include <pathplan.h>
 #include <vispath.h>
-#include <stdio.h>	/* temporary for debugging */
-#include <math.h>
 
 typedef struct {
 	Ppoly_t **list;
