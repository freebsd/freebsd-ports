--- server/dia/lex.l	Tue Jul  9 22:28:41 2002
+++ server/dia/lex.l	Mon Oct 10 10:47:16 2005
@@ -3,4 +3,5 @@
 
 %{
+#include <inttypes.h>
 #include "auservertype.h"
 #include "gram.h"
+++ clients/audio/widgets/Slider.c	Mon Oct 10 11:04:41 2005
@@ -32,4 +32,5 @@
 #include <X11/Xaw/Label.h>
 #include <X11/Xaw/Scrollbar.h>
+#include <inttypes.h>
 #include <stdio.h>
 #include "SliderP.h"
@@ -151,5 +152,5 @@
 			     (float) w->slider.value / w->slider.max, -1.0);
 
-	XtCallCallbacks((Widget) w, XtNcallback, (XtPointer) w->slider.value);
+	XtCallCallbacks((Widget) w, XtNcallback, (XtPointer)(intptr_t)w->slider.value);
     }
 }
@@ -162,5 +163,5 @@
 {
     SliderWidget    sw = (SliderWidget) swp;
-    int             position = (int) positionp;
+    intptr_t        position = (intptr_t) positionp;
 
     setValue(sw, sw->slider.value + (position > 0 ? -1 : 1), True, False);
