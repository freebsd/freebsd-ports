--- src/sd/bv/stdiagram.c.orig	Tue Mar 21 13:53:27 2000
+++ src/sd/bv/stdiagram.c	Wed Jul 18 01:29:15 2001
@@ -34,7 +34,7 @@
 #include "transitionarrow.h"
 #include "initialstatebox.h"
 #include "stdiagram.h"
-#include <values.h>
+#include <limits.h>
 
 const int STDiagram::BOX_WIDTH = 100;
 const int STDiagram::BOX_HEIGHT = 38;
@@ -356,7 +356,7 @@
 	total += stChecks->CheckEmptyActions(chkbuf);
 	total += stChecks->CheckNoActions(chkbuf);
 	total += stChecks->CheckCountEdgesFrom(Code::DECISION_POINT, 
-		Code::TRANSITION, 2, MAXINT, False, False, chkbuf);
+		Code::TRANSITION, 2, INT_MAX, False, False, chkbuf);
 	int sub = stChecks->CheckNodeCount(1, Code::INITIAL_STATE, chkbuf);
 	total += sub;
 	if (sub == 0) {
