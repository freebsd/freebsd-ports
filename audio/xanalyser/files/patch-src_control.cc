--- src/control.cc.orig	2018-01-19 00:48:36 UTC
+++ src/control.cc
@@ -566,7 +566,7 @@ analyser_callback (Widget, XtPointer client_data, XtPo
 				     XtWindow (analyser_drawing_w[n]));
 
 	    XExposeEvent* e = (XExposeEvent*) c->event;
-	    XRectangle rect = { e->x, e->y, e->width, e->height };
+	    XRectangle rect = { static_cast<short>(e->x), static_cast<short>(e->y), static_cast<unsigned short>(e->width), static_cast<unsigned short>(e->height) };
 	    analyser[n].draw (rect);
 
 	} break;
@@ -585,7 +585,7 @@ analyser_callback (Widget, XtPointer client_data, XtPo
 		case ButtonPress:
 		case MotionNotify: {
 		    XButtonPressedEvent* e = (XButtonPressedEvent*) c->event;
-		    XPoint point = { e->x, e->y };
+		    XPoint point = { static_cast<short>(e->x),static_cast<short>(e->y) };
 
 		    analyser[0].set_marker (point.x);
 		    analyser[1].set_marker (point.x);
@@ -709,7 +709,7 @@ scope_callback (Widget, XtPointer, XtPointer call_data
 		scope.realize (XtDisplay (scope_drawing_w), XtWindow (scope_drawing_w));
 
 	    XExposeEvent* e = (XExposeEvent*) c->event;
-	    XRectangle rect = { e->x, e->y, e->width, e->height };
+	    XRectangle rect = { static_cast<short>(e->x),static_cast<short>(e->y), static_cast<unsigned short>(e->width), static_cast<unsigned short>(e->height) };
 	    scope.draw (rect);
 
 	} break;
