--- gedit/gedit-print.c.orig	Thu Oct 16 22:22:09 2003
+++ gedit/gedit-print.c	Thu Oct 16 22:29:04 2003
@@ -388,6 +388,8 @@
 	
  	g_object_unref (gjob);
 
+	gtk_widget_destroy (pji->dialog);
+
 	if (pji->preview == PREVIEW)
 		gedit_print_job_info_destroy (pji, FALSE);
 	else
@@ -395,8 +397,6 @@
 		g_signal_handlers_disconnect_by_func (pji->pjob, (GCallback) page_cb, pji);
 		g_signal_handlers_disconnect_by_func (pji->pjob, (GCallback) preview_finished_cb, pji);
 	}
-
-	gtk_widget_destroy (pji->dialog);
 	
 	gtk_widget_show (preview);
 }
@@ -412,9 +412,9 @@
 	
  	g_object_unref (gjob);
 
-	gedit_print_job_info_destroy (pji, TRUE);
-
 	gtk_widget_destroy (pji->dialog);
+
+	gedit_print_job_info_destroy (pji, TRUE);
 }
 
 void 
