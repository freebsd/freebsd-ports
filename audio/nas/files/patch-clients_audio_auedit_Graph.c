--- clients/audio/auedit/Graph.c	Sun Jun 20 15:01:41 2004
+++ clients/audio/auedit/Graph.c	Mon Oct 10 11:21:15 2005
@@ -29,4 +29,5 @@
 
 #include "config.h"
+#include <inttypes.h>
 
 #if defined(HAVE_LIMITS_H)
@@ -453,5 +454,5 @@
     {
 	XtCallCallbacks((Widget) w, XtNleftProc,
-			(XtPointer) w->graph.leftMarker);
+			(XtPointer)(intptr_t)w->graph.leftMarker);
 	redraw = TRUE;
     }
@@ -460,5 +461,5 @@
     {
 	XtCallCallbacks((Widget) w, XtNrightProc,
-			(XtPointer) w->graph.rightMarker);
+			(XtPointer)(intptr_t)w->graph.rightMarker);
 	redraw = TRUE;
     }
@@ -540,8 +541,8 @@
     if (w->graph.marker == GraphLeftMarker)
 	XtCallCallbacks((Widget) w, XtNleftProc,
-			(XtPointer) w->graph.leftMarker);
+			(XtPointer)(intptr_t)w->graph.leftMarker);
     else
 	XtCallCallbacks((Widget) w, XtNrightProc,
-			(XtPointer) w->graph.rightMarker);
+			(XtPointer)(intptr_t)w->graph.rightMarker);
 }
 
