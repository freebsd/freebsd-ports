--- XMotif/main_w.c.orig	2007-11-23 21:34:10.000000000 +0100
+++ XMotif/main_w.c	2007-11-23 21:35:22.000000000 +0100
@@ -217,7 +217,7 @@
 					XmNbottomAttachment, XmATTACH_FORM,
 					NULL);
 
-   XtAddCallback(pause_button,XmNactivateCallback,pause_button_cb,NULL);
+   XtAddCallback(pause_button,XmNactivateCallback,(XtCallbackProc)pause_button_cb,NULL);
 
    start_button=XtVaCreateManagedWidget("start_button",xmPushButtonWidgetClass, header,
 					XmNleftAttachment, XmATTACH_WIDGET,
@@ -226,7 +226,7 @@
 					XmNbottomAttachment, XmATTACH_FORM,
 					NULL);
 
-   XtAddCallback(start_button,XmNactivateCallback,start_button_cb,NULL);
+   XtAddCallback(start_button,XmNactivateCallback,(XtCallbackProc)start_button_cb,NULL);
 
    XtManageChild(header);
 
@@ -270,8 +270,8 @@
 				       XmNbackground, the_environment.back_color,
 				       NULL);
 
-   XtAddEventHandler(network_w, StructureNotifyMask, False, resize_network_w_event_handler, NULL);
-   XtAddEventHandler(network_w, ExposureMask, False, redraw_lines_event_handler, NULL);
+   XtAddEventHandler(network_w, StructureNotifyMask, False, (XtEventHandler)resize_network_w_event_handler, NULL);
+   XtAddEventHandler(network_w, ExposureMask, False, (XtEventHandler)redraw_lines_event_handler, NULL);
 
    XtVaSetValues(scroll_w,
 		 XmNworkWindow, network_w,
