--- clients/audio/auedit/Graph.c.orig	2013-04-27 00:41:00 UTC
+++ clients/audio/auedit/Graph.c
@@ -28,6 +28,7 @@
  */
 
 #include "config.h"
+#include <inttypes.h>
 
 #if defined(HAVE_LIMITS_H)
 # include <limits.h>
@@ -452,14 +453,14 @@ GraphWidget     old,
     if (w->graph.leftMarker != old->graph.leftMarker)
     {
 	XtCallCallbacks((Widget) w, XtNleftProc,
-			(XtPointer) w->graph.leftMarker);
+			(XtPointer)(intptr_t)w->graph.leftMarker);
 	redraw = TRUE;
     }
 
     if (w->graph.rightMarker != old->graph.rightMarker)
     {
 	XtCallCallbacks((Widget) w, XtNrightProc,
-			(XtPointer) w->graph.rightMarker);
+			(XtPointer)(intptr_t)w->graph.rightMarker);
 	redraw = TRUE;
     }
 
@@ -539,10 +540,10 @@ XButtonEvent   *event;
 
     if (w->graph.marker == GraphLeftMarker)
 	XtCallCallbacks((Widget) w, XtNleftProc,
-			(XtPointer) w->graph.leftMarker);
+			(XtPointer)(intptr_t)w->graph.leftMarker);
     else
 	XtCallCallbacks((Widget) w, XtNrightProc,
-			(XtPointer) w->graph.rightMarker);
+			(XtPointer)(intptr_t)w->graph.rightMarker);
 }
 
 /* public functions */
