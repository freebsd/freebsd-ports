--- XMotif/edit.c.orig	2007-11-23 21:36:17.000000000 +0100
+++ XMotif/edit.c	2007-11-23 21:40:19.000000000 +0100
@@ -73,11 +73,11 @@
 void selection_confirm_kill_cb(Widget widget);
 
 MenuItem edit_items[] = {
-  {"Create Component",&xmPushButtonGadgetClass,NULL,NULL,NULL,XmNactivateCallback,edit_create_cb,(XtPointer)E_CREATE_COMPONENT,(MenuItem *)NULL,NULL},
-  {"",&xmSeparatorGadgetClass,NULL,NULL,NULL,NULL,NULL,NULL,(MenuItem *)NULL,NULL},
-  {"Kill Selection",&xmPushButtonGadgetClass,NULL,NULL,NULL,XmNactivateCallback,selection_confirm_kill_cb,(XtPointer)E_REMOVE_SELECTION,(MenuItem *)NULL,NULL},
-  {"Group Selection",&xmPushButtonGadgetClass,NULL,NULL,NULL,XmNactivateCallback,edit_group_cb,(XtPointer)E_GROUP_SELECTION,(MenuItem *)NULL,NULL},
-  {"Unselect All",&xmPushButtonGadgetClass,NULL,NULL,NULL,XmNactivateCallback,edit_unsel_cb,(XtPointer)E_UNSELECT_ALL,(MenuItem *)NULL,NULL},
+  {"Create Component",&xmPushButtonGadgetClass,'\0',NULL,NULL,XmNactivateCallback,edit_create_cb,(XtPointer)E_CREATE_COMPONENT,(MenuItem *)NULL,NULL},
+  {"",&xmSeparatorGadgetClass,'\0',NULL,NULL,NULL,NULL,NULL,(MenuItem *)NULL,NULL},
+  {"Kill Selection",&xmPushButtonGadgetClass,'\0',NULL,NULL,XmNactivateCallback,selection_confirm_kill_cb,(XtPointer)E_REMOVE_SELECTION,(MenuItem *)NULL,NULL},
+  {"Group Selection",&xmPushButtonGadgetClass,'\0',NULL,NULL,XmNactivateCallback,edit_group_cb,(XtPointer)E_GROUP_SELECTION,(MenuItem *)NULL,NULL},
+  {"Unselect All",&xmPushButtonGadgetClass,'\0',NULL,NULL,XmNactivateCallback,edit_unsel_cb,(XtPointer)E_UNSELECT_ALL,(MenuItem *)NULL,NULL},
   NULL
 };
 
@@ -167,9 +167,9 @@
   if (l_empty(selected)) return;
   if (!question_dialog) {
     question_dialog=XmCreateQuestionDialog(main_w,"confirm_kill_selection_dialog",NULL,0);
-    XtAddCallback(question_dialog,XmNokCallback,edit_remove_cb,NULL);
-    XtAddCallback(question_dialog,XmNokCallback,XtUnmanageChild,NULL);
-    XtAddCallback(question_dialog,XmNcancelCallback,XtUnmanageChild,NULL);
+    XtAddCallback(question_dialog,XmNokCallback,(XtCallbackProc)edit_remove_cb,NULL);
+    XtAddCallback(question_dialog,XmNokCallback,(XtCallbackProc)XtUnmanageChild,NULL);
+    XtAddCallback(question_dialog,XmNcancelCallback,(XtCallbackProc)XtUnmanageChild,NULL);
   }
   else {
     XRaiseWindow(XtDisplay(question_dialog),XtWindow(XtParent(question_dialog)));
@@ -233,7 +233,7 @@
    box_w=0;
    box_h=0;
   
-   for(i=0;component_types[i].class!=NULL;i++) {
+   for(i=0;component_types[i].class!=0;i++) {
       Widget icon;     
 	
       x=X_OFFSET+col*COL_SPACING;
@@ -265,7 +265,7 @@
 				       XmNtopWidget, icon_box,
 				       NULL);
 
-   XtAddCallback(done_button,XmNactivateCallback,create_comp_done_cb,form);
+   XtAddCallback(done_button,XmNactivateCallback,(XtCallbackProc)create_comp_done_cb,form);
    return(form);
 }
 
