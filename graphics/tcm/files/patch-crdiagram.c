--- src/sd/dv/crdiagram.c.orig	Mon Sep 25 13:34:40 2000
+++ src/sd/dv/crdiagram.c	Wed Jul 18 01:27:46 2001
@@ -38,7 +38,7 @@
 #include "textbox.h"
 #include "comment.h"
 #include "crdiagram.h"
-#include <values.h>
+#include <limits.h>
 
 CRDiagram::CRDiagram(Config *c, CRWindow *d, CRViewer *v, CRGraph *g): 
 	   ERDiagram(c, d, v, g) {
@@ -481,7 +481,7 @@
 		Code::EMPTY_EDGE, 2, chkbuf);
 	// Check that classes have not 1 comp. function.
 	total += crChecks->CheckCountEdgesFrom(
-		Code::CLASS_NODE, Code::COMPONENT_FUNCTION, 2, MAXINT, 
+		Code::CLASS_NODE, Code::COMPONENT_FUNCTION, 2, INT_MAX, 
 		True, False, chkbuf);
 	// Check that rel. classes are not spec. of classes.
 	total += crChecks->CheckRelationshipIsaClassNode(chkbuf);
