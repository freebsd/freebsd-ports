
$FreeBSD$

--- SciTEGTK.cxx	2002/01/04 12:53:45	1.1
+++ SciTEGTK.cxx	2002/01/04 12:54:45
@@ -2429,7 +2429,7 @@
 	                   GtkSignalFunc(MousePress), gthis);
 
 	gtk_window_set_title(GTK_WINDOW(PWidget(wSciTE)), appName);
-	const int useDefault = 0x100000000;
+	const int useDefault = 0x10000000;
 	int left = props.GetInt("position.left", useDefault);
 	int top = props.GetInt("position.top", useDefault);
 	int width = props.GetInt("position.width", useDefault);
