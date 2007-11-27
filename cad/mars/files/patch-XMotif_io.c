--- XMotif/io.c.orig	2007-11-23 21:31:17.000000000 +0100
+++ XMotif/io.c	2007-11-23 21:33:26.000000000 +0100
@@ -77,7 +77,7 @@
 void update_screen()
 {
    update_clock();
-   if (screen_update != NULL) {
+   if (screen_update != OFF) {
       update_meters_and_info_windows();
    }
    XFlush(the_environment.the_display);
@@ -240,9 +240,9 @@
   base_position=XmTextGetLastPosition(message_w);
   XmTextSetInsertionPosition(message_w,base_position);
 
-  XtAddCallback(message_w,XmNactivateCallback, input_text, NULL);
-  XtAddCallback(message_w,XmNmotionVerifyCallback, input_text, NULL);
-  XtAddCallback(message_w,XmNmodifyVerifyCallback, input_text, NULL);
+  XtAddCallback(message_w,XmNactivateCallback, (XtCallbackProc)input_text, NULL);
+  XtAddCallback(message_w,XmNmotionVerifyCallback, (XtCallbackProc)input_text, NULL);
+  XtAddCallback(message_w,XmNmodifyVerifyCallback, (XtCallbackProc)input_text, NULL);
 
   input=0;
   XmTextSetEditable(message_w,True);
@@ -251,9 +251,9 @@
   }
   XmTextSetEditable(message_w,False);
 
-  XtRemoveCallback(message_w,XmNactivateCallback, input_text, NULL);
-  XtRemoveCallback(message_w,XmNmotionVerifyCallback, input_text, NULL);
-  XtRemoveCallback(message_w,XmNmodifyVerifyCallback, input_text, NULL);
+  XtRemoveCallback(message_w,XmNactivateCallback, (XtCallbackProc)input_text, NULL);
+  XtRemoveCallback(message_w,XmNmotionVerifyCallback, (XtCallbackProc)input_text, NULL);
+  XtRemoveCallback(message_w,XmNmodifyVerifyCallback, (XtCallbackProc)input_text, NULL);
 
   str=XmTextGetString(message_w);
 
