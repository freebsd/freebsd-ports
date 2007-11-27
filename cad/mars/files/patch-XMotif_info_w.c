--- XMotif/info_w.c.orig	2007-11-23 22:04:53.000000000 +0100
+++ XMotif/info_w.c	2007-11-23 22:06:58.000000000 +0100
@@ -374,7 +374,7 @@
 		  NULL);
 
     if (parameter->p_flags & (InputMask | ModifyMask))
-       XtAddCallback(textfield, XmNactivateCallback, change_parameter_cb, window_data);
+       XtAddCallback(textfield, XmNactivateCallback, (XtCallbackProc)change_parameter_cb, window_data);
     else
        XtVaSetValues(textfield, XmNeditable,False,NULL);
 
@@ -413,7 +413,7 @@
 				 XmNbackground, bg,
 				 XmNset, (window_data->initial_hide_settings & HIDE_CHILDREN)? True : False,
 				 NULL);
-  XtAddCallback(toggle, XmNvalueChangedCallback, comp_info_children_toggle_cb, window_data); 
+  XtAddCallback(toggle, XmNvalueChangedCallback, (XtCallbackProc)comp_info_children_toggle_cb, window_data); 
 
 
 /* METER TOGGLE */
@@ -421,7 +421,7 @@
 				 XmNbackground, bg,
 				 XmNset, (window_data->initial_hide_settings & HIDE_METERS)? True : False,
 				 NULL);
-  XtAddCallback(toggle, XmNvalueChangedCallback, comp_info_meter_toggle_cb, window_data); 
+  XtAddCallback(toggle, XmNvalueChangedCallback, (XtCallbackProc)comp_info_meter_toggle_cb, window_data); 
 
   XtManageChild(row_col);
   XtManageChild(form);
@@ -461,7 +461,7 @@
      Widget w;
      CompInfoWinData *window_data;
 {
-  XtRemoveCallback(w,XmNokCallback, comp_info_kill_action, window_data);
+  XtRemoveCallback(w,XmNokCallback, (XtCallbackProc)comp_info_kill_action, window_data);
   XtRemoveCallback(w,XmNokCallback, close_confirm_kill_comp_dialog, window_data);
   XtRemoveCallback(w,XmNcancelCallback, close_confirm_kill_comp_dialog, window_data);    
   XtUnmanageChild(w);
@@ -481,15 +481,15 @@
     question_dialog=XmCreateQuestionDialog(main_w,"confirm_kill_component_dialog",NULL,0);
   }
   
-  XtAddCallback(question_dialog,XmNokCallback, comp_info_kill_action, window_data);
+  XtAddCallback(question_dialog,XmNokCallback, (XtCallbackProc)comp_info_kill_action, window_data);
   XtAddCallback(question_dialog,XmNokCallback, close_confirm_kill_comp_dialog, window_data);
   XtAddCallback(question_dialog,XmNcancelCallback, close_confirm_kill_comp_dialog, window_data);    
 
   pos.x=((XButtonEvent *)cbs->event)->x_root;
   pos.y=((XButtonEvent *)cbs->event)->y_root;
-  XtAddCallback(XtParent(question_dialog), XmNpopupCallback, SetShellPosition, &pos);
+  XtAddCallback(XtParent(question_dialog), XmNpopupCallback, (XtCallbackProc)SetShellPosition, &pos);
   XtManageChild(question_dialog);
-  XtRemoveCallback(XtParent(question_dialog), XmNpopupCallback, SetShellPosition, &pos);
+  XtRemoveCallback(XtParent(question_dialog), XmNpopupCallback, (XtCallbackProc)SetShellPosition, &pos);
 }
 
 /**********************************************************************************************************************************************/
@@ -803,7 +803,7 @@
 		  XmNleftAttachment, XmATTACH_FORM,
 		  NULL);
     
-    XtAddCallback(textfield,XmNactivateCallback, change_group_name_cb, window_data);
+    XtAddCallback(textfield,XmNactivateCallback, (XtCallbackProc)change_group_name_cb, window_data);
   }
 
   sep=CreateSeparator(group_info_w,XmSINGLE_LINE,name_input);
@@ -864,7 +864,7 @@
      Widget w;
      CompInfoWinData *window_data;
 {
-  XtRemoveCallback(w,XmNokCallback, group_info_kill_action, window_data);
+  XtRemoveCallback(w,XmNokCallback, (XtCallbackProc)group_info_kill_action, window_data);
   XtRemoveCallback(w,XmNokCallback, close_confirm_kill_group_dialog, window_data);
   XtRemoveCallback(w,XmNcancelCallback, close_confirm_kill_group_dialog, window_data);    
   XtUnmanageChild(w);
@@ -882,15 +882,15 @@
   if (!question_dialog) {
     question_dialog=XmCreateQuestionDialog(main_w,"confirm_kill_group_dialog",NULL,0);
   }
-  XtAddCallback(question_dialog, XmNokCallback, group_info_kill_action, window_data);
+  XtAddCallback(question_dialog, XmNokCallback, (XtCallbackProc)group_info_kill_action, window_data);
   XtAddCallback(question_dialog, XmNokCallback, close_confirm_kill_group_dialog, window_data);
   XtAddCallback(question_dialog, XmNcancelCallback, close_confirm_kill_group_dialog, window_data);
 
   pos.x=((XButtonEvent *)cbs->event)->x_root;
   pos.y=((XButtonEvent *)cbs->event)->y_root;
-  XtAddCallback(XtParent(question_dialog), XmNpopupCallback, SetShellPosition, &pos);
+  XtAddCallback(XtParent(question_dialog), XmNpopupCallback, (XtCallbackProc)SetShellPosition, &pos);
   XtManageChild(question_dialog);
-  XtRemoveCallback(XtParent(question_dialog), XmNpopupCallback, SetShellPosition, &pos);
+  XtRemoveCallback(XtParent(question_dialog), XmNpopupCallback, (XtCallbackProc)SetShellPosition, &pos);
 }
 
 /**********************************************************************************************************************************************/
