--- src/tX_mastergui.cc.orig	Sat Feb  1 22:20:23 2003
+++ src/tX_mastergui.cc	Sat Feb  1 22:20:49 2003
@@ -1125,7 +1125,7 @@
 	gtk_widget_destroy(GTK_WIDGET(mbox));
 }
 
-void tx_note(const char *message, bool isError=false)
+void tx_note(const char *message, bool isError)
 {
 	char buffer[4096]="terminatorX ";
 	if (isError) {
