--- src/sd/bv/rpdiagram.c.orig	Mon Jul 26 12:44:03 1999
+++ src/sd/bv/rpdiagram.c	Wed Jul 18 01:29:02 2001
@@ -34,7 +34,7 @@
 #include "line.h"
 #include "rpdiagram.h"
 #include "diagramchecks.h"
-#include <values.h>
+#include <limits.h>
 
 const int RPDiagram::BOX_WIDTH = 58;
 const int RPDiagram::BOX_HEIGHT = 38;
@@ -247,7 +247,7 @@
 	chkbuf = "";
 	unsigned total = 0;
 	total += checks->CheckNodeCount(
-			1, MAXINT, Code::PROCESS_GRAPH_ROOT, chkbuf);
+			1, INT_MAX, Code::PROCESS_GRAPH_ROOT, chkbuf);
 	if (total == 0) {
 		total += checks->CheckNamelessNodes(
 				Code::PROCESS_GRAPH_ROOT, chkbuf);
