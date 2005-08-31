--- w_modepanel.c.orig	Mon Sep 16 23:11:35 2002
+++ w_modepanel.c	Wed Aug 31 09:49:42 2005
@@ -132,9 +132,11 @@
 /* button selection event handler */
 static void     sel_mode_but();
 
+#ifndef XAW3D
 /* popup message over button when mouse enters it */
 static void     mode_balloon_trigger();
 static void     mode_unballoon();
+#endif
 
 /* popdown message */
 static void     turn_on();
@@ -414,14 +416,21 @@
 	/* left button changes mode */
 	XtAddEventHandler(sw->widget, ButtonPressMask, False,
 			  sel_mode_but, (XtPointer) sw);
+#ifndef XAW3D
 	/* popup when mouse passes over button */
 	XtAddEventHandler(sw->widget, EnterWindowMask, False,
 			  mode_balloon_trigger, (XtPointer) sw);
 	XtAddEventHandler(sw->widget, LeaveWindowMask, False,
 			  mode_unballoon, (XtPointer) sw);
+#endif
 	XtOverrideTranslations(sw->widget,
 			       XtParseTranslationTable(mode_translations));
     }
+
+#ifdef XAW3D
+    update_modepanel();
+#endif
+
     return;
 }
 
@@ -467,6 +476,28 @@
     SetValues(mode_panel);
 }
 
+#ifdef XAW3D
+update_modepanel()
+{
+    register int    i;
+    register mode_sw_info *sw;
+
+    /*
+     * We must test for the widgets, as this is called by
+     * w_cmdpanel.c:refresh_view_menu().
+     */
+
+    for (i = 0; i < NUM_MODE_SW; ++i) {
+	sw = &mode_switches[i];
+	if (!sw->widget)
+	    continue;
+	if (appres.showballoons) {
+	    XawTipEnable(sw->widget, sw->modemsg);
+	} else
+	    XawTipDisable(sw->widget);
+    }
+}
+#else
 /* come here when the mouse passes over a button in the mode panel */
 
 static	Widget mode_balloon_popup = (Widget) 0;
@@ -557,6 +588,7 @@
 	mode_balloon_popup = (Widget) 0;
     }
 }
+#endif
 
 /* come here when a button is pressed in the mode panel */
 
@@ -585,45 +617,46 @@
     else if (highlighting)
 	erase_objecthighlight();
 
+#ifndef XAW3D
     /* if this command popups a window, destroy the balloon popup now. See the
        note above about this above the command panel definition. */
     if (msw->popup) {
 	mode_unballoon((Widget) 0, (XtPointer) 0, (XEvent*) 0, (Boolean*) 0);
     }
     app_flush();
+#endif
 
     if (xbutton.button == Button1) {	/* left button */
 	turn_off_current();
 	turn_on(msw);
-	if (msw->mode == F_UPDATE) {	/* map the set/clr/toggle button for update */
+
+	update_indpanel(0);	/* first remove ind buttons */
+	XtUnmanageChild(ind_panel);
+	if (msw->mode != F_UPDATE)
+	    XtUnmanageChild(upd_ctrl);
+	FirstArg(XtNwidth, 1);	/* force a resize to update scrollbar */
+	SetValues(ind_panel);
+	if (msw->mode == F_UPDATE) {
 	    if (cur_mode != F_UPDATE) {
-		update_indpanel(0);	/* first remove ind buttons */
-		XtUnmanageChild(ind_panel);
+		/* map the set/clr/toggle button for update */
 		XtManageChild(upd_ctrl);
-		/* get the width of the update control panel */
-		/* now put the ind_panel to our right */
-		FirstArg(XtNfromHoriz, upd_ctrl);
-		NextArg(XtNwidth, INDPANEL_WD-UPD_CTRL_WD-2*INTERNAL_BW); /* resize it */
-		SetValues(ind_panel);
-		XtManageChild(ind_panel);
-		update_indpanel(msw->indmask);	/* now manage the relevant buttons */
 	    }
-	} else { 	/* turn off the update boxes if not in update mode */
-	    if (cur_mode == F_UPDATE) {	/* if previous mode is update and current */
-		update_indpanel(0);	/* is not, first remove ind buttons */
+	    /* set the adjacent widget and width */
+	    FirstArg(XtNfromHoriz, upd_ctrl);
+	    NextArg(XtNwidth, INDPANEL_WD-UPD_CTRL_WD-2*INTERNAL_BW);
+	} else {
+	    if (cur_mode == F_UPDATE) {
+		/* unmap the set/clr/toggle button for update */
 		unmanage_update_buts();
-		XtUnmanageChild(ind_panel);
-		XtUnmanageChild(upd_ctrl);
-		/* now put the ind_panel to the right of the canvas */
-		FirstArg(XtNfromHoriz, NULL);
-		NextArg(XtNwidth, INDPANEL_WD);	/* resize it */
-		SetValues(ind_panel);
-		XtManageChild(ind_panel);
-		update_indpanel(msw->indmask);	/* now manage the relevant buttons */
-	    } else {
-		update_indpanel(msw->indmask);	/* just update indicator buttons */
 	    }
+	    /* clear the adjacent widget and set width */
+	    FirstArg(XtNfromHoriz, NULL);
+	    NextArg(XtNwidth, INDPANEL_WD);
 	}
+	SetValues(ind_panel);
+	XtManageChild(ind_panel);
+	update_indpanel(msw->indmask);	/* now manage the relevant buttons */
+
 	put_msg(msw->modemsg);
 	if ((cur_mode == F_GLUE || cur_mode == F_BREAK) &&
 	    msw->mode != F_GLUE && msw->mode != F_BREAK) {
