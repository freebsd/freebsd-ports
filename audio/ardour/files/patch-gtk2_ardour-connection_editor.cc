--- gtk2_ardour/connection_editor.cc.orig
+++ gtk2_ardour/connection_editor.cc
@@ -502,9 +502,9 @@ ConnectionEditor::display_connection_sta
 	frame_label += _("\"");
 	port_frame.set_label (frame_label);
 
-	for (slist<ScrolledWindow *>::iterator i = port_displays.begin(); i != port_displays.end(); ) {
+	for (boost::container::slist<ScrolledWindow *>::iterator i = port_displays.begin(); i != port_displays.end(); ) {
 		
-		slist<ScrolledWindow *>::iterator tmp;
+		boost::container::slist<ScrolledWindow *>::iterator tmp;
 
 		tmp = i;
 		tmp++;
@@ -612,7 +612,7 @@ ConnectionEditor::connection_port_button
 
 		tview->set_name ("ConnectionEditorPortListSelected");
 
-		for (slist<ScrolledWindow *>::iterator i = port_displays.begin(); i != port_displays.end(); ++i) {
+		for (boost::container::slist<ScrolledWindow *>::iterator i = port_displays.begin(); i != port_displays.end(); ++i) {
 
 			Widget *child = (*i)->get_child();
 
