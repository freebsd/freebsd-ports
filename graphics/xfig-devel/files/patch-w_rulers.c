--- w_rulers.c.orig	Sat Oct 12 01:13:53 2002
+++ w_rulers.c	Wed Aug 31 09:49:42 2005
@@ -117,9 +117,11 @@
 static void	sideruler_selected();
 static void	sideruler_exposed();
 
+#ifndef XAW3D
 /* popup message over button when mouse enters it */
 static void     unit_balloon_trigger();
 static void     unit_unballoon();
+#endif
 
 /* turn these into macros so we can use them in
    struct initialization */
@@ -356,17 +358,46 @@
     unitbox_sw = XtCreateWidget("unitbox", labelWidgetClass, tool,
 				Args, ArgCount);
     XtAppAddActions(tool_app, unitbox_actions, XtNumber(unitbox_actions));
+#ifndef XAW3D
     /* popup when mouse passes over button */
     XtAddEventHandler(unitbox_sw, EnterWindowMask, False,
 		      unit_balloon_trigger, (XtPointer) unitbox_sw);
     XtAddEventHandler(unitbox_sw, LeaveWindowMask, False,
 		      unit_unballoon, (XtPointer) unitbox_sw);
+#endif
     XtOverrideTranslations(unitbox_sw,
 			   XtParseTranslationTable(unitbox_translations));
+
+#ifdef XAW3D
+    update_rulerpanel();
+#endif
 }
 
 static Widget	unit_popup, unit_panel, cancel, set, beside, below, label;
 
+#ifdef XAW3D
+update_rulerpanel()
+{
+    char msg[80];
+
+    strcpy(msg, "Pan to 0,0        ");
+    if (appres.flipvisualhints)
+	sprintf(msg + strlen(msg), "(right button)");
+    else
+	sprintf(msg + strlen(msg), "(left button)");
+    sprintf(msg + strlen(msg), "\nSet Units/Scale   ");
+    if (appres.flipvisualhints)
+	sprintf(msg + strlen(msg), "(left button)");
+    else
+	sprintf(msg + strlen(msg), "(right button)");
+
+    if (unitbox_sw)
+	if (appres.showballoons)
+	    XawTipEnable(unitbox_sw, msg);
+	else
+	    XawTipDisable(unitbox_sw);
+}
+#else
 /* come here when the mouse passes over the unit box */
 
 static	Widget unit_balloon_popup = (Widget) 0;
@@ -474,6 +505,7 @@
 	unit_balloon_popup = (Widget) 0;
     }
 }
+#endif
 
 /* handle unit/scale settings */
 
