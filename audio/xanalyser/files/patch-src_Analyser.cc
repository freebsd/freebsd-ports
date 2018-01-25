--- src/Analyser.cc.orig	2018-01-19 00:36:36 UTC
+++ src/Analyser.cc
@@ -146,7 +146,7 @@ Analyser::resize (bool redraw)
     marker[1] = f2sx (f[1]);
 
     if (redraw) {
-	XRectangle rect = { 0, 0, width, height };
+	XRectangle rect = { 0, 0, static_cast<unsigned short>(width), static_cast<unsigned short>(height) };
 	draw (rect);
     }
 }
@@ -169,7 +169,7 @@ Analyser::clear (bool drawit)
     calcfoo ();
 
     if (drawit) {
-	XRectangle rect = { 0, 0, width, height };
+	XRectangle rect = { 0, 0, static_cast<unsigned short>(width), static_cast<unsigned short>(height) };
 	draw (rect);
     }
 }
@@ -188,7 +188,7 @@ Analyser::drawpeaktext (bool showit)
 
 	snprintf (peak_text, 10, "%i", (int) peak_f);
 
-	peak_sx = f2sx (peak_f) - (strlen (peak_text) * font_width) / 2;
+        peak_sx = f2sx (peak_f) - (strlen (peak_text) * font_width) / 2;
 	peak_sy = db2sy (peak_db) - 6;
 
 	XSetForeground (display, gc, xanalyser.markercolor);
@@ -203,7 +203,7 @@ void
 Analyser::drawpeakmarker ()
 {
     for (int m = 0; m < 2; m++) {
-	XRectangle rect = { marker[m], 0, 1, height };
+	XRectangle rect = { static_cast<short>(marker[m]), 0, 1, static_cast<unsigned short>(height) };
 	draw (rect);
     }
 }
@@ -251,13 +251,13 @@ Analyser::drawgrid (bool withtext)
 	else
 	    XSetForeground (display, gc, xanalyser.minorgridcolor);
 
-	XDrawLine (display, window, gc, 0, sy, width - 1, sy);
+	XDrawLine (display, window, gc, 0, sy, static_cast<unsigned short>(width) - 1, sy);
 
 	if (withtext) {
 	    const int size = 10;
 	    char buffer[size];
 	    snprintf (buffer, size, "%+d", db);
-	    XDrawString (display, window, gc, width - 2 - font_width *
+	    XDrawString (display, window, gc, static_cast<unsigned short>(width) - 2 - font_width *
 			 strlen (buffer), sy - 2, buffer, strlen (buffer));
 	}
     }
@@ -280,7 +280,7 @@ Analyser::draw (XRectangle rect, bool complete)
     if (complete) {
 
 	XSetForeground (display, gc, xanalyser.backgroundcolor);
-	XFillRectangle (display, window, gc, 0, 0, width, height);
+	XFillRectangle (display, window, gc, 0, 0, static_cast<unsigned short>(width), height);
 
 	XSetForeground (display, gc, xanalyser.datacolor);
 	for (int sx = first; sx <= last; sx++) {
@@ -344,7 +344,7 @@ Analyser::realize (Display* display, Window window)
 
     gc = XCreateGC (display, window, gc_mask, &gc_values);
 
-    // get width and height
+    // get static_cast<unsigned short>(width) and height
 
     myXGetDrawableSize (display, window, &width, &height);
 
@@ -382,8 +382,8 @@ Analyser::realize (Display* display, Window window)
     envelope ();
 
     marker[0] = 0;
-    // note: it might be that width - 1 != num_fft - 1
-    marker[1] = width - 1;
+    // note: it might be that static_cast<unsigned short>(width) - 1 != num_fft - 1
+    marker[1] = static_cast<unsigned short>(width) - 1;
 
     return true;
 }
@@ -427,7 +427,7 @@ Analyser::shot (const int32_t* buffer, int channel, bo
     analyse (buffer, channel);
 
     if (drawit) {
-	XRectangle rect = { 0, 0, width, height };
+	XRectangle rect = { 0, 0, static_cast<unsigned short>(width), static_cast<unsigned short>(height) };
 	draw (rect, false);
     }
 
@@ -608,7 +608,7 @@ Analyser::set_search (bool search)
 	drawpeaktext (true);
 
 	for (int m = 0; m < 2; m++) {
-	    XRectangle rect = { marker[m], 0, 1, height };
+	    XRectangle rect = { static_cast<short>(marker[m]), 0, 1, static_cast<unsigned short>(height) };
 	    draw (rect);
 	}
 
@@ -618,7 +618,7 @@ Analyser::set_search (bool search)
 	drawpeaktext (false);
 
 	for (int m = 0; m < 2; m++) {
-	    XRectangle rect = { marker[m], 0, 1, height };
+	    XRectangle rect = { static_cast<short>(marker[m]), 0, 1, static_cast<unsigned short>(height) };
 	    draw (rect);
 	}
 
@@ -647,7 +647,7 @@ Analyser::set_marker (short sx)
 
     // remove old marker and text
 
-    XRectangle rect = { old, 0, 1, height };
+    XRectangle rect = { old, 0, 1, static_cast<unsigned short>(height) };
     draw (rect);
 
     XSetClipMask (display, gc, None);
@@ -662,7 +662,7 @@ Analyser::set_marker (short sx)
     peaksearch (true);
 
     for (int m = 0; m < 2; m++) {
-	XRectangle rect = { marker[m], 0, 1, height };
+	XRectangle rect = { static_cast<short>(marker[m]), 0, 1, static_cast<unsigned short>(height) };
 	draw (rect);
     }
 
