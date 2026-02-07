--- clients/audio/widgets/Slider.c.orig	2013-04-27 00:41:00 UTC
+++ clients/audio/widgets/Slider.c
@@ -31,6 +31,7 @@
 #include <X11/StringDefs.h>
 #include <X11/Xaw/Label.h>
 #include <X11/Xaw/Scrollbar.h>
+#include <inttypes.h>
 #include <stdio.h>
 #include "SliderP.h"
 
@@ -148,7 +149,7 @@ setValue(SliderWidget w, int value, Bool
 	    XawScrollbarSetThumb(w->slider.scrollbarW,
 			     (float) w->slider.value / w->slider.max, -1.0);
 
-	XtCallCallbacks((Widget) w, XtNcallback, (XtPointer) w->slider.value);
+	XtCallCallbacks((Widget) w, XtNcallback, (XtPointer)(intptr_t)w->slider.value);
     }
 }
 
@@ -156,7 +157,7 @@ static void
 scroll(Widget w, XtPointer swp, XtPointer positionp)
 {
     SliderWidget    sw = (SliderWidget) swp;
-    int             position = (int) positionp;
+    intptr_t        position = (intptr_t) positionp;
 
     setValue(sw, sw->slider.value + (position > 0 ? -1 : 1), True, False);
 }
--- server/dia/lex.l.orig	2013-04-27 00:41:06 UTC
+++ server/dia/lex.l
@@ -2,6 +2,7 @@
 /* $NCDId: @(#)lex.l,v 1.1 1996/04/24 17:01:06 greg Exp $ */
 
 %{
+#include <inttypes.h>
 #include "auservertype.h"
 #include "gram.h"
 #include "nasconf.h"
