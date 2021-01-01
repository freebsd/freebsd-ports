--- gtk2_ardour/io_selector.cc.orig
+++ gtk2_ardour/io_selector.cc
@@ -389,9 +389,9 @@ IOSelector::display_ports ()
 			limit = io->n_outputs();
 		}
 		
-		for (slist<TreeView *>::iterator i = port_displays.begin(); i != port_displays.end(); ) {
+		for (boost::container::slist<TreeView *>::iterator i = port_displays.begin(); i != port_displays.end(); ) {
 			
-			slist<TreeView *>::iterator tmp;
+			boost::container::slist<TreeView *>::iterator tmp;
 			
 			tmp = i;
 			++tmp;
@@ -632,13 +632,13 @@ IOSelector::connection_button_release (G
 void
 IOSelector::select_next_treeview ()
 {
-	slist<TreeView*>::iterator next;
+	boost::container::slist<TreeView*>::iterator next;
 
 	if (port_displays.empty() || port_displays.size() == 1) {
 		return;
 	}
 
-	for (slist<TreeView *>::iterator i = port_displays.begin(); i != port_displays.end(); ++i) {
+	for (boost::container::slist<TreeView *>::iterator i = port_displays.begin(); i != port_displays.end(); ++i) {
 
 		if ((*i)->get_name() == "IOSelectorPortListSelected") {
 
@@ -681,7 +681,7 @@ IOSelector::select_treeview (TreeView* t
 		gtk_widget_queue_draw (ccol->button);
 	}
 
-	for (slist<TreeView*>::iterator i = port_displays.begin(); i != port_displays.end(); ++i) {
+	for (boost::container::slist<TreeView*>::iterator i = port_displays.begin(); i != port_displays.end(); ++i) {
 		if (*i == tview) {
 			continue;
 		}
