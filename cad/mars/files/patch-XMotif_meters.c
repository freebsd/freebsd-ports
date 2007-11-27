--- XMotif/meters.c.orig	2007-11-23 21:40:49.000000000 +0100
+++ XMotif/meters.c	2007-11-23 21:45:10.000000000 +0100
@@ -570,7 +570,7 @@
 	    buttons[n]=XmStringCreateSimple(meter_types[i].meter_name);
 	 }
 
-	 popup=XmVaCreateSimplePopupMenu(parent,"meter_type_popup_menu",change_meter_type,
+	 popup=XmVaCreateSimplePopupMenu(parent,"meter_type_popup_menu",(XtCallbackProc)change_meter_type,
 					 XmVaPUSHBUTTON, buttons[0], 0, NULL, NULL,
 					 XmVaPUSHBUTTON, buttons[1], 0, NULL, NULL,
 					 XmVaPUSHBUTTON, buttons[2], 0, NULL, NULL,
@@ -594,7 +594,7 @@
 				      XmNbackground, bg,
 				      NULL);
 	 XmStringFree(str);
-	 XtAddCallback(item, XmNactivateCallback, popup_change_meter_type_menu, popup);
+	 XtAddCallback(item, XmNactivateCallback, (XtCallbackProc)popup_change_meter_type_menu, popup);
       }
       *textfield_return=NULL;
       break;
@@ -744,10 +744,10 @@
       data->previous_value=new_string(value);
       data->new_value=NULL;
       if (edit_flags & EDIT_ON_ACTIVATE) {
-	 XtAddCallback(textfield, XmNactivateCallback, preview_textfield, NULL);
+	 XtAddCallback(textfield, XmNactivateCallback, (XtCallbackProc)preview_textfield, NULL);
 	 XtAddCallback(textfield, XmNactivateCallback, edit_callback, edit_calldata);    
-	 XtAddCallback(textfield, XmNactivateCallback, update_textfield, NULL);
-	 XtAddCallback(textfield, XmNdestroyCallback, free_TextFieldData, NULL);
+	 XtAddCallback(textfield, XmNactivateCallback, (XtCallbackProc)update_textfield, NULL);
+	 XtAddCallback(textfield, XmNdestroyCallback, (XtCallbackProc)free_TextFieldData, NULL);
       }
    }
    else {
@@ -898,7 +898,7 @@
    
    data=GetTextFieldData(w);
    if (data->value_changed) {
-      if (sscanf(data->new_value, "%lf", &scale) == NULL) {
+      if (!sscanf(data->new_value, "%lf", &scale)) {
 	 data->action=RESTORE_PREVIOUS_VALUE;
 	 return;
       }	
@@ -925,7 +925,7 @@
 
    data=GetTextFieldData(w);
    if (data->value_changed) {
-      if (sscanf(data->new_value, "%lf", &increment) == NULL) {
+      if (!sscanf(data->new_value, "%lf", &increment)) {
 	 data->action=RESTORE_PREVIOUS_VALUE;
 	 return;
       }
@@ -967,7 +967,7 @@
    
    data=GetTextFieldData(w);
    if (data->value_changed) {
-      if (sscanf(data->new_value, "%f", &increment) == NULL) {
+      if (!sscanf(data->new_value, "%f", &increment)) {
 	 data->action=RESTORE_PREVIOUS_VALUE;
 	 return;
       }	
@@ -1004,7 +1004,7 @@
             
    data=GetTextFieldData(w);
    if (data->value_changed) {
-      if (sscanf(data->new_value, "%f", &increment) == NULL) {
+      if (!sscanf(data->new_value, "%f", &increment)) {
 	 data->action=RESTORE_PREVIOUS_VALUE;
 	 return;
       }	
@@ -1041,7 +1041,7 @@
    
    data=GetTextFieldData(w);
    if (data->value_changed) {
-      if (sscanf(data->new_value, "%f", &increment) == NULL) {
+      if (!sscanf(data->new_value, "%f", &increment)) {
 	 data->action=RESTORE_PREVIOUS_VALUE;
 	 return;
       }	
@@ -1078,7 +1078,7 @@
    
    data=GetTextFieldData(w);
    if (data->value_changed) {
-      if (sscanf(data->new_value, "%f", &increment) == NULL) {
+      if (!sscanf(data->new_value, "%f", &increment)) {
 	 data->action=RESTORE_PREVIOUS_VALUE;
 	 return;
       }	
@@ -1439,7 +1439,7 @@
 				      NULL);
   
   XtOverrideTranslations(draw_area, the_environment.meter_window_translations);
-  XtAddEventHandler(draw_area, ExposureMask, False, meter_expose_event_handler, meter);
+  XtAddEventHandler(draw_area, ExposureMask, False, (XtEventHandler)meter_expose_event_handler, meter);
 
   XtVaSetValues(form, XmNwidth, (Dimension)meter->width, NULL);
 
@@ -2143,7 +2143,7 @@
   if (xinput(answer_string, 20) == 0)
     {
       xprintclear();  /* user just typed return */
-      return (NULL); 
+      return (0); 
     }
   xprintclear();
 
