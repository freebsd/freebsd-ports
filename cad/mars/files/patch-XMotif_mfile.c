--- XMotif/mfile.c.orig	1994-03-15 05:43:09.000000000 +0100
+++ XMotif/mfile.c	2007-11-23 21:59:35.000000000 +0100
@@ -80,17 +80,17 @@
 #define F_QUIT 8
 
 MenuItem file_items[] = {
-  {"",&xmSeparatorGadgetClass,NULL,NULL,NULL,NULL,NULL,NULL,(MenuItem *)NULL,NULL},
-  {"New",&xmPushButtonGadgetClass,NULL,NULL,NULL,XmNactivateCallback,confirm_clear_network,(XtPointer)F_NEW,(MenuItem *)NULL,NULL},
-  {"Open",&xmPushButtonGadgetClass,NULL,NULL,NULL,XmNactivateCallback,file_cb,(XtPointer)F_OPEN,(MenuItem *)NULL,NULL},
-  {"Save",&xmPushButtonGadgetClass,NULL,NULL,NULL,XmNactivateCallback,file_cb,(XtPointer)F_SAVE,(MenuItem *)NULL,NULL},
-  {"Snap",&xmPushButtonGadgetClass,NULL,NULL,NULL,XmNactivateCallback,file_cb,(XtPointer)F_SNAP,(MenuItem *)NULL,NULL},
-  {"Print",&xmPushButtonGadgetClass,NULL,NULL,NULL,XmNactivateCallback,file_cb,(XtPointer)F_PRINT,(MenuItem *)NULL,NULL},
-  {"",&xmSeparatorGadgetClass,NULL,NULL,NULL,NULL,NULL,NULL,(MenuItem *)NULL,NULL},
-  {"Stop Record",&xmPushButtonGadgetClass,NULL,NULL,NULL,XmNactivateCallback,record,(XtPointer)F_RECORD,(MenuItem *)NULL,initialize_record_button},
-  {"Play",&xmPushButtonGadgetClass,NULL,NULL,NULL,XmNactivateCallback,file_cb,(XtPointer)F_PLAY,(MenuItem *)NULL,NULL},
-  {"",&xmSeparatorGadgetClass,NULL,NULL,NULL,NULL,NULL,NULL,(MenuItem *)NULL,NULL},
-  {"Quit",&xmPushButtonGadgetClass,NULL,NULL,NULL,XmNactivateCallback,confirm_quit,(XtPointer)F_QUIT,(MenuItem *)NULL,NULL},
+  {"",&xmSeparatorGadgetClass,'\0',NULL,NULL,NULL,NULL,NULL,(MenuItem *)NULL,NULL},
+  {"New",&xmPushButtonGadgetClass,'\0',NULL,NULL,XmNactivateCallback,confirm_clear_network,(XtPointer)F_NEW,(MenuItem *)NULL,NULL},
+  {"Open",&xmPushButtonGadgetClass,'\0',NULL,NULL,XmNactivateCallback,file_cb,(XtPointer)F_OPEN,(MenuItem *)NULL,NULL},
+  {"Save",&xmPushButtonGadgetClass,'\0',NULL,NULL,XmNactivateCallback,file_cb,(XtPointer)F_SAVE,(MenuItem *)NULL,NULL},
+  {"Snap",&xmPushButtonGadgetClass,'\0',NULL,NULL,XmNactivateCallback,file_cb,(XtPointer)F_SNAP,(MenuItem *)NULL,NULL},
+  {"Print",&xmPushButtonGadgetClass,'\0',NULL,NULL,XmNactivateCallback,file_cb,(XtPointer)F_PRINT,(MenuItem *)NULL,NULL},
+  {"",&xmSeparatorGadgetClass,'\0',NULL,NULL,NULL,NULL,NULL,(MenuItem *)NULL,NULL},
+  {"Stop Record",&xmPushButtonGadgetClass,'\0',NULL,NULL,XmNactivateCallback,record,(XtPointer)F_RECORD,(MenuItem *)NULL,initialize_record_button},
+  {"Play",&xmPushButtonGadgetClass,'\0',NULL,NULL,XmNactivateCallback,file_cb,(XtPointer)F_PLAY,(MenuItem *)NULL,NULL},
+  {"",&xmSeparatorGadgetClass,'\0',NULL,NULL,NULL,NULL,NULL,(MenuItem *)NULL,NULL},
+  {"Quit",&xmPushButtonGadgetClass,'\0',NULL,NULL,XmNactivateCallback,confirm_quit,(XtPointer)F_QUIT,(MenuItem *)NULL,NULL},
   NULL
 };
 
@@ -858,9 +858,9 @@
 
   if (!question_dialog) {
     question_dialog=XmCreateQuestionDialog(main_w_shell,"confirm_clear_network_dialog",NULL,0);
-    XtAddCallback(question_dialog,XmNokCallback,file_new_cb,NULL);
-    XtAddCallback(question_dialog,XmNokCallback,XtUnmanageChild,NULL);
-    XtAddCallback(question_dialog,XmNcancelCallback,XtUnmanageChild,NULL);
+    XtAddCallback(question_dialog,XmNokCallback,(XtCallbackProc)file_new_cb,NULL);
+    XtAddCallback(question_dialog,XmNokCallback,(XtCallbackProc)XtUnmanageChild,NULL);
+    XtAddCallback(question_dialog,XmNcancelCallback,(XtCallbackProc)XtUnmanageChild,NULL);
   }
   XtManageChild(question_dialog);
   XRaiseWindow(the_environment.the_display, XtWindow(XtParent(question_dialog)));
@@ -896,9 +896,9 @@
   }
   if (!question_dialog) {
     question_dialog=XmCreateQuestionDialog(main_w_shell,"confirm_quit_dialog",NULL,0);
-    XtAddCallback(question_dialog,XmNokCallback,file_quit_cb,NULL);
-    XtAddCallback(question_dialog,XmNokCallback,XtUnmanageChild,NULL);
-    XtAddCallback(question_dialog,XmNcancelCallback,XtUnmanageChild,NULL);
+    XtAddCallback(question_dialog,XmNokCallback,(XtCallbackProc)file_quit_cb,NULL);
+    XtAddCallback(question_dialog,XmNokCallback,(XtCallbackProc)XtUnmanageChild,NULL);
+    XtAddCallback(question_dialog,XmNcancelCallback,(XtCallbackProc)XtUnmanageChild,NULL);
   }
   XtManageChild(question_dialog);
   XRaiseWindow(the_environment.the_display, XtWindow(XtParent(question_dialog)));
@@ -936,7 +936,7 @@
 		   XmNtopAttachment, XmATTACH_WIDGET,
 		   XmNtopWidget, sep,
 		   NULL);
-     XtAddCallback(fs_box, XmNcancelCallback, cancel_file_selection, NULL);
+     XtAddCallback(fs_box, XmNcancelCallback, (XtCallbackProc)cancel_file_selection, NULL);
      XtManageChild(fs_box);
   }
   else {
@@ -945,23 +945,23 @@
   
   switch(item) {
   case F_OPEN:
-     XtAddCallback(fs_box, XmNokCallback, load_network, NULL);
+     XtAddCallback(fs_box, XmNokCallback, (XtCallbackProc)load_network, NULL);
      SetLabelString(label, "Open Network");
      break;
   case F_SAVE:     
-     XtAddCallback(fs_box, XmNokCallback, save_network, FALSE);
+     XtAddCallback(fs_box, XmNokCallback, (XtCallbackProc)save_network, FALSE);
      SetLabelString(label, "Save Network");
      break;
   case F_SNAP:
-     XtAddCallback(fs_box, XmNokCallback, save_network, TRUE);
+     XtAddCallback(fs_box, XmNokCallback, (XtCallbackProc)save_network, (XtPointer) TRUE);
      SetLabelString(label, "Save Snapshot");
      break;
   case F_PRINT:
-     XtAddCallback(fs_box, XmNokCallback, print, NULL);
+     XtAddCallback(fs_box, XmNokCallback, (XtCallbackProc)print, NULL);
      SetLabelString(label, "Print Network");
      break;
   case F_PLAY:
-     XtAddCallback(fs_box, XmNokCallback, play, NULL);
+     XtAddCallback(fs_box, XmNokCallback, (XtCallbackProc)play, NULL);
      SetLabelString(label, "Playback Events");
      break;
   default: WARNING("Unexpected item no. in file_cb.\n"); break;
