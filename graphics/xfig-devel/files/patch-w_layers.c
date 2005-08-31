--- w_layers.c.orig	Tue Nov  5 20:38:18 2002
+++ w_layers.c	Wed Aug 31 09:49:42 2005
@@ -63,9 +63,11 @@
 static	XtCallbackProc	switch_layer_mode();
 static	XtActionProc	layer_exposed();
 
+#ifndef XAW3D
 /* popup message over command button when mouse enters it */
 static void     layer_balloon_trigger();
 static void     layer_unballoon();
+#endif
 
 static  void	draw_layer_button();
 static  void	draw_layer_buttons();
@@ -144,11 +146,13 @@
     below = all_active_but = XtCreateManagedWidget("all_active", commandWidgetClass,
 				layer_form, Args, ArgCount);
     XtAddCallback(below, XtNcallback, (XtCallbackProc)all_active, (XtPointer) NULL);
+#ifndef XAW3D
     /* popup when mouse passes over button */
     XtAddEventHandler(below, EnterWindowMask, False,
 			  layer_balloon_trigger, (XtPointer) "Display all depths");
     XtAddEventHandler(below, LeaveWindowMask, False,
 			  layer_unballoon, (XtPointer) NULL);
+#endif
 
     FirstArg(XtNlabel, "All Off");
     NextArg(XtNfromVert, below);
@@ -159,11 +163,13 @@
     below = all_inactive_but = XtCreateManagedWidget("all_inactive", commandWidgetClass,
 				layer_form, Args, ArgCount);
     XtAddCallback(below, XtNcallback, (XtCallbackProc)all_inactive, (XtPointer) NULL);
+#ifndef XAW3D
     /* popup when mouse passes over button */
     XtAddEventHandler(below, EnterWindowMask, False,
 			  layer_balloon_trigger, (XtPointer) "Hide all depths");
     XtAddEventHandler(below, LeaveWindowMask, False,
 			  layer_unballoon, (XtPointer) NULL);
+#endif
 
     FirstArg(XtNlabel, "Toggle ");
     NextArg(XtNfromVert, below);
@@ -174,11 +180,13 @@
     below = toggle_all_but = XtCreateManagedWidget("toggle_all", commandWidgetClass,
 				layer_form, Args, ArgCount);
     XtAddCallback(below, XtNcallback, (XtCallbackProc)toggle_all, (XtPointer) NULL);
+#ifndef XAW3D
     /* popup when mouse passes over button */
     XtAddEventHandler(below, EnterWindowMask, False,
 			  layer_balloon_trigger, (XtPointer) "Toggle displayed/hidden depths");
     XtAddEventHandler(below, LeaveWindowMask, False,
 			  layer_unballoon, (XtPointer) NULL);
+#endif
 
     /* radio buttons to switch between graying out inactive layers or blanking altogether */
 
@@ -286,12 +294,13 @@
     NextArg(XtNright, XtChainRight);
     layer_viewp = XtCreateManagedWidget("layer_viewp", viewportWidgetClass, 
 			layer_viewform, Args, ArgCount);
+#ifndef XAW3D
     /* popup when mouse passes over button */
-
     XtAddEventHandler(layer_viewp, EnterWindowMask, False,
 			  layer_balloon_trigger, (XtPointer) "Display or hide any depth");
     XtAddEventHandler(layer_viewp, LeaveWindowMask, False,
 			  layer_unballoon, (XtPointer) NULL);
+#endif
     XtAddEventHandler(layer_viewp, StructureNotifyMask, False,
 			  update_layers, (XtPointer) NULL);
 
@@ -321,6 +330,9 @@
     XtOverrideTranslations(layer_canvas,
 			   XtParseTranslationTable(layer_translations));
 
+#ifdef XAW3D
+    update_layerpanel();
+#endif
 }
 
 /* now that the mouse function and indicator panels have been sized
@@ -728,6 +740,36 @@
 	return False;
 }
 
+#ifdef XAW3D
+update_layerpanel()
+{
+    /*
+     * We must test for the widgets, as this is called by
+     * w_cmdpanel.c:refresh_view_menu().
+     */
+
+    if (all_active_but)
+	if (appres.showballoons)
+	    XawTipEnable(all_active_but, "Display all depths");
+	else
+	    XawTipDisable(all_active_but);
+    if (all_inactive_but)
+	if (appres.showballoons)
+	    XawTipEnable(all_inactive_but, "Hide all depths");
+	else
+	    XawTipDisable(all_inactive_but);
+    if (toggle_all_but)
+	if (appres.showballoons)
+	    XawTipEnable(toggle_all_but, "Toggle displayed/hidden depths");
+	else
+	    XawTipDisable(toggle_all_but);
+    if (layer_viewp)
+	if (appres.showballoons)
+	    XawTipEnable(layer_viewp, "Display or hide any depth");
+	else
+	    XawTipDisable(layer_viewp);
+}
+#else
 static	Widget layer_balloon_popup = (Widget) 0;
 static	XtIntervalId balloon_id = (XtIntervalId) 0;
 static	Widget balloon_w;
@@ -831,6 +873,7 @@
 	layer_balloon_popup = (Widget) 0;
     }
 }
+#endif
 
 /* map/unmap the depth manager on the right side */
 
