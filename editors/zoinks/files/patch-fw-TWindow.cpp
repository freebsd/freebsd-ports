--- fw/TWindow.cpp.orig	2003-04-16 21:38:57.000000000 +0200
+++ fw/TWindow.cpp	2007-11-04 22:35:45.000000000 +0100
@@ -502,7 +502,7 @@
 			return false;
 		
 		XIMStyles* supportedStyles;
-		XGetIMValues(xim, XNQueryInputStyle, &supportedStyles, NULL, NULL);
+		XGetIMValues(xim, XNQueryInputStyle, &supportedStyles, (char *)NULL);
 		if (!supportedStyles || supportedStyles->count_styles == 0)
 			return false;
 			
@@ -542,12 +542,12 @@
 		
 		TFont* font = GetFont();
 		ASSERT(font && font->GetFontSet());
-		XVaNestedList	preeditAttributes = XVaCreateNestedList(0, XNFontSet, font->GetFontSet(), XNSpotLocation, &point, XNArea, &rect, NULL);
+		XVaNestedList	preeditAttributes = XVaCreateNestedList(0, XNFontSet, font->GetFontSet(), XNSpotLocation, &point, XNArea, &rect, (char *)NULL);
 		ASSERT(preeditAttributes);
 	//	XVaNestedList	statusAttributes = XVaCreateNestedList(0, XNFontSet, font->GetFontSet(), NULL);
 	//	ASSERT(statusAttributes);
 	
-		XIC xic = XCreateIC(xim, XNInputStyle, style, XNClientWindow, fWindow, XNFocusWindow, fWindow, XNPreeditAttributes, preeditAttributes, /*XNStatusAttributes, statusAttributes, */ NULL);
+		XIC xic = XCreateIC(xim, XNInputStyle, style, XNClientWindow, fWindow, XNFocusWindow, fWindow, XNPreeditAttributes, preeditAttributes, /*XNStatusAttributes, statusAttributes, */ (char *)NULL);
 		if (xic)
 			fInputContext = new TInputContext(xic);
 			
@@ -657,7 +657,14 @@
 {
 	time = CurrentTime;	// ignore time for now
 
+#if 0
+	Pietro Cerutti <gahr@gahr.ch> 
+	We may not be the active window
+	anymore by this time
+
 	ASSERT(sPointerGrabWindow == this);
+#endif
+	if(sPointerGrabWindow != this) return;
 
 	XUngrabPointer(sDisplay, time);
 	
