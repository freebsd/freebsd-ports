--- XMotif/view.c.orig	2007-11-23 22:00:21.000000000 +0100
+++ XMotif/view.c	2007-11-23 22:02:13.000000000 +0100
@@ -75,13 +75,13 @@
 void close_all_groups(Widget w);
 
 MenuItem view_items[] = {
-  {"Update Screen", &xmToggleButtonGadgetClass, NULL, NULL, NULL, XmNvalueChangedCallback, toggle_update_screen, (XtPointer)NULL, (MenuItem *)NULL,initialize_update_screen_toggle},
-  {"",&xmSeparatorGadgetClass, NULL, NULL, NULL, NULL, NULL, NULL, (MenuItem *)NULL,NULL},
-  {"Open Meter Window", &xmPushButtonGadgetClass, NULL, NULL, NULL, XmNactivateCallback, view_meter_cb, (XtPointer)V_METER_WINDOW, (MenuItem *)NULL, NULL}, 
-  {"Close All Information Windows", &xmPushButtonGadgetClass, NULL, NULL, NULL, XmNactivateCallback, close_all_info_w, (XtPointer)V_CLOSE_ALL_INFO_WINDOWS, (MenuItem *)NULL, NULL},
-  {"Close All Groups", &xmPushButtonGadgetClass, NULL, NULL, NULL, XmNactivateCallback, close_all_groups, (XtPointer)V_CLOSE_ALL_GROUPS, (MenuItem *)NULL, NULL},
-  {"",&xmSeparatorGadgetClass, NULL, NULL, NULL, NULL, NULL, NULL, (MenuItem *)NULL,NULL},
-  {"Hide", &xmPushButtonGadgetClass, NULL, NULL, NULL, XmNactivateCallback, view_hide_cb, (XtPointer)V_HIDE, (MenuItem *)NULL,NULL},
+  {"Update Screen", &xmToggleButtonGadgetClass, '\0', NULL, NULL, XmNvalueChangedCallback, toggle_update_screen, (XtPointer)NULL, (MenuItem *)NULL,initialize_update_screen_toggle},
+  {"",&xmSeparatorGadgetClass, '\0', NULL, NULL, NULL, NULL, NULL, (MenuItem *)NULL,NULL},
+  {"Open Meter Window", &xmPushButtonGadgetClass, '\0', NULL, NULL, XmNactivateCallback, view_meter_cb, (XtPointer)V_METER_WINDOW, (MenuItem *)NULL, NULL}, 
+  {"Close All Information Windows", &xmPushButtonGadgetClass, '\0', NULL, NULL, XmNactivateCallback, close_all_info_w, (XtPointer)V_CLOSE_ALL_INFO_WINDOWS, (MenuItem *)NULL, NULL},
+  {"Close All Groups", &xmPushButtonGadgetClass, '\0', NULL, NULL, XmNactivateCallback, close_all_groups, (XtPointer)V_CLOSE_ALL_GROUPS, (MenuItem *)NULL, NULL},
+  {"",&xmSeparatorGadgetClass, '\0', NULL, NULL, NULL, NULL, NULL, (MenuItem *)NULL,NULL},
+  {"Hide", &xmPushButtonGadgetClass, '\0', NULL, NULL, XmNactivateCallback, view_hide_cb, (XtPointer)V_HIDE, (MenuItem *)NULL,NULL},
   NULL
 };
 
@@ -284,7 +284,7 @@
 			     XmNrightAttachment, XmATTACH_FORM,
 			     NULL);
     
-     for(num_components=0;component_types[num_components].class!=NULL;num_components++);
+     for(num_components=0;component_types[num_components].class!=0;num_components++);
      hide_components_toggles=(Widget *)sim_malloc(sizeof(Widget)*num_components);
 
      for(i=0;i<num_components;i++) {
@@ -297,7 +297,7 @@
 							   XmNset, (the_environment.hide_settings>>i & 0x1L)? True:False,
 							   NULL);
 	XmStringFree(str);
-	XtAddCallback(hide_components_toggles[i], XmNvalueChangedCallback, hide_w_component_toggle_cb, (XtPointer)i);
+	XtAddCallback(hide_components_toggles[i], XmNvalueChangedCallback, (XtCallbackProc)hide_w_component_toggle_cb, (XtPointer)i);
      }
      str=XmStringCreateSimple("METERS");
      hide_meters_toggle=XtVaCreateManagedWidget("toggle_button", xmToggleButtonGadgetClass,row_col,
@@ -308,7 +308,7 @@
 						XmNset, (the_environment.hide_meters)? True:False,
 						NULL);
      XmStringFree(str);
-     XtAddCallback(hide_meters_toggle, XmNvalueChangedCallback, hide_w_component_toggle_cb, (XtPointer)TYPE_METER);
+     XtAddCallback(hide_meters_toggle, XmNvalueChangedCallback, (XtCallbackProc)hide_w_component_toggle_cb, (XtPointer)TYPE_METER);
     
      XtManageChild(row_col);
     
