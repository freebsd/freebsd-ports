--- src/sd/dv/ucdiagram.c.orig	Tue Jul 17 23:49:03 2001
+++ src/sd/dv/ucdiagram.c	Tue Jul 17 23:49:44 2001
@@ -41,7 +41,7 @@
 #include "ucdiagram.h"
 #include "note.h"
 #include <stdio.h>
-#include <values.h>
+#include <limits.h>
 
 UCDiagram::UCDiagram(Config *c, UCWindow *d, UCViewer *v, UCGraph *g): 
 	   ERDiagram(c, d, v, g) {
