--- XMotif/options.c.orig	2007-11-23 22:02:50.000000000 +0100
+++ XMotif/options.c	2007-11-23 22:04:08.000000000 +0100
@@ -70,17 +70,17 @@
 Widget delay_button;
 
 MenuItem opmodes_radiobox[] = {
-  {"Continuous", &xmToggleButtonGadgetClass, NULL, NULL, NULL, XmNvalueChangedCallback, opmodes_cb, (XtPointer)CONTINUOUS_BUTTON, (MenuItem*)NULL, initialize_continuous_button},
-  {"Event Step", &xmToggleButtonGadgetClass, NULL, NULL ,NULL, XmNvalueChangedCallback, opmodes_cb, (XtPointer)EVENT_STEP_BUTTON, (MenuItem*)NULL, initialize_event_step_button},
-  {"Time Step", &xmToggleButtonGadgetClass, NULL, NULL, NULL, XmNvalueChangedCallback, opmodes_cb, (XtPointer)TIME_STEP_BUTTON, (MenuItem*)NULL, initialize_time_step_button},
+  {"Continuous", &xmToggleButtonGadgetClass, '\0', NULL, NULL, XmNvalueChangedCallback, opmodes_cb, (XtPointer)CONTINUOUS_BUTTON, (MenuItem*)NULL, initialize_continuous_button},
+  {"Event Step", &xmToggleButtonGadgetClass, '\0', NULL ,NULL, XmNvalueChangedCallback, opmodes_cb, (XtPointer)EVENT_STEP_BUTTON, (MenuItem*)NULL, initialize_event_step_button},
+  {"Time Step", &xmToggleButtonGadgetClass, '\0', NULL, NULL, XmNvalueChangedCallback, opmodes_cb, (XtPointer)TIME_STEP_BUTTON, (MenuItem*)NULL, initialize_time_step_button},
   NULL
 };
 
 MenuItem options_items[] = {
-  {"Delay", &xmPushButtonGadgetClass, NULL, NULL, NULL, XmNactivateCallback, delay_cb, (XtPointer)O_DELAY, (MenuItem *)NULL, initialize_delay_button},
-  {"", &xmSeparatorGadgetClass, NULL, NULL, NULL, NULL, NULL, NULL, (MenuItem *)NULL, NULL},
-  {"Operating Mode", &xmCascadeButtonGadgetClass, NULL, NULL, NULL, XmNactivateCallback, NULL, (XtPointer)O_OPERATING_MODE,opmodes_radiobox, NULL},
-  {"Resize Network", &xmPushButtonGadgetClass, NULL, NULL, NULL, XmNactivateCallback, resize_dialog_cb, (XtPointer)O_RESIZE, (MenuItem *)NULL, NULL},
+  {"Delay", &xmPushButtonGadgetClass, '\0', NULL, NULL, XmNactivateCallback, delay_cb, (XtPointer)O_DELAY, (MenuItem *)NULL, initialize_delay_button},
+  {"", &xmSeparatorGadgetClass, '\0', NULL, NULL, NULL, NULL, NULL, (MenuItem *)NULL, NULL},
+  {"Operating Mode", &xmCascadeButtonGadgetClass, '\0', NULL, NULL, XmNactivateCallback, NULL, (XtPointer)O_OPERATING_MODE,opmodes_radiobox, NULL},
+  {"Resize Network", &xmPushButtonGadgetClass, '\0', NULL, NULL, XmNactivateCallback, resize_dialog_cb, (XtPointer)O_RESIZE, (MenuItem *)NULL, NULL},
   NULL
 };
 
@@ -241,7 +241,7 @@
      /* Width Textfield */
      sprintf(buf,"%d",the_environment.network_width);
      width_input=CreateTextInput(resize_dialog,"width",buf,&textfields[0]);
-     XtAddCallback(textfields[0],XmNactivateCallback,resize_check_input,&resize_max_w);
+     XtAddCallback(textfields[0],XmNactivateCallback,(XtCallbackProc)resize_check_input,&resize_max_w);
      XtVaSetValues(width_input,
 		   XmNleftAttachment, XmATTACH_FORM,
 		   XmNrightAttachment, XmATTACH_FORM,
@@ -252,7 +252,7 @@
    /* Height Textfield */
       sprintf(buf,"%d",the_environment.network_height);
       height_input=CreateTextInput(resize_dialog,"height",buf,&textfields[1]);
-      XtAddCallback(textfields[1],XmNactivateCallback,resize_check_input,&resize_max_h);
+      XtAddCallback(textfields[1],XmNactivateCallback,(XtCallbackProc)resize_check_input,&resize_max_h);
       XtVaSetValues(height_input,
 		    XmNleftAttachment, XmATTACH_FORM,
 		    XmNrightAttachment, XmATTACH_FORM,
@@ -262,7 +262,7 @@
 
    /* Minimize Button */
       minimize_button=XtVaCreateManagedWidget("minimize_button", xmPushButtonWidgetClass, resize_dialog, NULL);
-      XtAddCallback(minimize_button, XmNactivateCallback, resize_minimize, textfields);
+      XtAddCallback(minimize_button, XmNactivateCallback, (XtCallbackProc)resize_minimize, textfields);
       XtVaSetValues(minimize_button,
 		    XmNleftAttachment, XmATTACH_FORM,
 		    XmNrightAttachment, XmATTACH_FORM,
