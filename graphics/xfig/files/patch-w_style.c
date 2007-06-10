--- w_style.c.orig	Tue Jul 26 09:40:02 2005
+++ w_style.c
@@ -696,7 +696,7 @@
     if (style_dirty_flag) {
 	status = popup_query(QUERY_YESNOCAN, "Do you wish to save the changes you made to the styles?");
 	if (status == RESULT_YES)
-	    save_style((Widget) 0, (XEvent *) 0);
+	    save_style((Widget) 0, (XButtonEvent *) 0);
 	return status;
     }
     return RESULT_YES;
