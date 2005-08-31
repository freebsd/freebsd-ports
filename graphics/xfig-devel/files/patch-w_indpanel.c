--- w_indpanel.c.orig	Sat Oct 19 01:05:41 2002
+++ w_indpanel.c	Wed Aug 31 09:49:42 2005
@@ -60,9 +60,11 @@
 
 #define MAX_ARROWSIZE 3 /* maximum value for cur_arrowsizeshown */
 
+#ifndef XAW3D
 /* popup message over button when mouse enters it */
 static void     ind_balloon_trigger();
 static void     ind_unballoon();
+#endif
 
 /***** value panel set translations *****/
 static String set_translations =
@@ -471,7 +473,7 @@
    0x3f, 0x02, 0x7f, 0x02, 0xff, 0x02, 0xff, 0x03};
 
 /* create a ind_sw_info struct for the update widget 
-   so we can use the balloon routines */
+   so we can use the balloon routines or the Tip widget */
 
 static ind_sw_info upd_sw_info, upd_set_sw_info, upd_clr_sw_info, upd_tog_sw_info;
 
@@ -506,10 +508,12 @@
     strcpy(upd_sw_info.line1,"Selects which settings are updated");
     upd_sw_info.line2[0] = '\0';
     upd_sw_info.sw_width = 70;  /* rough guess */
+#ifndef XAW3D
     XtAddEventHandler(upd_ctrl, EnterWindowMask, False,
 			ind_balloon_trigger, (XtPointer) &upd_sw_info);
     XtAddEventHandler(upd_ctrl, LeaveWindowMask, False,
 			ind_unballoon, (XtPointer) &upd_sw_info);
+#endif
 
     FirstArg(XtNborderWidth, 0);
     NextArg(XtNjustify, XtJustifyCenter);
@@ -518,11 +522,12 @@
     NextArg(XtNinternalHeight, 0);
     upd_ctrl_lab = XtCreateManagedWidget("upd_ctrl_label", labelWidgetClass,
 			upd_ctrl, Args, ArgCount);
-
+#ifndef XAW3D
     XtAddEventHandler(upd_ctrl_lab, EnterWindowMask, False,
 			ind_balloon_trigger, (XtPointer) &upd_sw_info);
     XtAddEventHandler(upd_ctrl_lab, LeaveWindowMask, False,
 			ind_unballoon, (XtPointer) &upd_sw_info);
+#endif
 
     FirstArg(XtNdefaultDistance, 0);
     NextArg(XtNborderWidth, 0);
@@ -545,10 +550,12 @@
     strcpy(upd_set_sw_info.line1,"Sets all update flags");
     upd_set_sw_info.line2[0] = '\0';
     upd_set_sw_info.sw_width = UPD_BITS+6;
+#ifndef XAW3D
     XtAddEventHandler(set_upd, EnterWindowMask, False,
 			ind_balloon_trigger, (XtPointer) &upd_set_sw_info);
     XtAddEventHandler(set_upd, LeaveWindowMask, False,
 			ind_unballoon, (XtPointer) &upd_set_sw_info);
+#endif
 
     clr_upd = XtCreateManagedWidget("clr_upd", commandWidgetClass,
 			upd_ctrl_btns, Args, ArgCount);
@@ -558,10 +565,12 @@
     strcpy(upd_clr_sw_info.line1,"Clears all update flags");
     upd_clr_sw_info.line2[0] = '\0';
     upd_clr_sw_info.sw_width = UPD_BITS+6;
+#ifndef XAW3D
     XtAddEventHandler(clr_upd, EnterWindowMask, False,
 			ind_balloon_trigger, (XtPointer) &upd_clr_sw_info);
     XtAddEventHandler(clr_upd, LeaveWindowMask, False,
 			ind_unballoon, (XtPointer) &upd_clr_sw_info);
+#endif
 
     tog_upd = XtCreateManagedWidget("tog_upd", commandWidgetClass,
 			upd_ctrl_btns, Args, ArgCount);
@@ -571,10 +580,12 @@
     strcpy(upd_tog_sw_info.line1,"Toggles all update flags");
     upd_tog_sw_info.line2[0] = '\0';
     upd_tog_sw_info.sw_width = UPD_BITS+6;
+#ifndef XAW3D
     XtAddEventHandler(tog_upd, EnterWindowMask, False,
 			ind_balloon_trigger, (XtPointer) &upd_tog_sw_info);
     XtAddEventHandler(tog_upd, LeaveWindowMask, False,
 			ind_unballoon, (XtPointer) &upd_tog_sw_info);
+#endif
 
     /* start with all components affected by update */
     cur_updatemask = I_UPDATEMASK;
@@ -669,11 +680,13 @@
 	/* (callbacks pass same data for ANY button) */
 	XtAddEventHandler(sw->button, ButtonReleaseMask, False,
 			  sel_ind_but, (XtPointer) sw);
+#ifndef XAW3D
 	/* popup when mouse passes over button */
 	XtAddEventHandler(sw->button, EnterWindowMask, False,
 			  ind_balloon_trigger, (XtPointer) sw);
 	XtAddEventHandler(sw->button, LeaveWindowMask, False,
 			  ind_unballoon, (XtPointer) sw);
+#endif
 	XtOverrideTranslations(sw->button,
 			       XtParseTranslationTable(ind_translations));
     }
@@ -898,6 +911,7 @@
 
 }
 
+#ifndef XAW3D
 /* come here when the mouse passes over a button in the indicator panel */
 
 static	Widget ind_balloon_popup = (Widget) 0;
@@ -980,6 +994,7 @@
 	ind_balloon_popup = (Widget) 0;
     }
 }
+#endif
 
 generate_choice_pixmaps(isw)
     ind_sw_info	   *isw;
@@ -1002,13 +1017,62 @@
 update_indpanel(mask)
     unsigned long   mask;
 {
+#ifdef XAW3D
+    char	msg[60];
+#endif
     register int    i;
     register ind_sw_info *isw;
 
+    /*
+     * We must test for the widgets, as this is called by
+     * w_cmdpanel.c:refresh_view_menu().
+     */
+
+#ifdef XAW3D
+    if (upd_ctrl)
+	if (appres.showballoons)
+	    XawTipEnable(upd_ctrl, upd_sw_info.line1);
+	else
+	    XawTipDisable(upd_ctrl);
+    if (upd_ctrl_lab)
+	if (appres.showballoons)
+	    XawTipEnable(upd_ctrl_lab, upd_sw_info.line1);
+	else
+	    XawTipDisable(upd_ctrl_lab);
+    if (set_upd)
+	if (appres.showballoons)
+	    XawTipEnable(set_upd, upd_set_sw_info.line1);
+	else
+	    XawTipDisable(set_upd);
+    if (clr_upd)
+	if (appres.showballoons)
+	    XawTipEnable(clr_upd, upd_clr_sw_info.line1);
+	else
+	    XawTipDisable(clr_upd);
+    if (tog_upd)
+	if (appres.showballoons)
+	    XawTipEnable(tog_upd, upd_tog_sw_info.line1);
+	else
+	    XawTipDisable(tog_upd);
+    for (isw = ind_switches, i = 0; i < NUM_IND_SW; isw++, i++) {
+	if (!isw->button)
+	    continue;
+	if (appres.showballoons) {
+	    sprintf(msg, "%s", isw->line1);
+	    if (strlen(isw->line2))
+		sprintf(msg + strlen(msg), " %s", isw->line2);
+	    XawTipEnable(isw->button, msg);
+	} else
+	    XawTipDisable(isw->button);
+    }
+#endif
+
     /* only update current mask if user wants to see relevant ind buttons */
     if (appres.ShowAllButtons)
 	return;
 
+    if (!ind_box)
+	return;
     cur_indmask = mask;
     XtUnmanageChild(ind_box);
     for (isw = ind_switches, i = 0; i < NUM_IND_SW; isw++, i++) {
@@ -1034,9 +1098,11 @@
     XButtonEvent xbutton;
     ind_sw_info *isw = (ind_sw_info *) closure;
 
+#ifndef XAW3D
     /* since this command popups a window, destroy the balloon popup now. */
     ind_unballoon((Widget) 0, (XtPointer) 0, (XEvent*) 0, (Boolean*) 0);
     app_flush();
+#endif
 
     xbutton = event->xbutton;
 #ifdef WHEELMOUSE
