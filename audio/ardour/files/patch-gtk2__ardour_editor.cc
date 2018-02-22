--- gtk2_ardour/editor.cc.orig	2012-03-16 14:33:28 UTC
+++ gtk2_ardour/editor.cc
@@ -803,16 +803,16 @@ Editor::Editor ()
 	list<Glib::RefPtr<Gdk::Pixbuf> > window_icons;
 	Glib::RefPtr<Gdk::Pixbuf> icon;
 
-	if ((icon = ::get_icon ("ardour_icon_16px")) != 0) {
+	if ((icon = ::get_icon ("ardour_icon_16px"))) {
 		window_icons.push_back (icon);
 	}
-	if ((icon = ::get_icon ("ardour_icon_22px")) != 0) {
+	if ((icon = ::get_icon ("ardour_icon_22px"))) {
 		window_icons.push_back (icon);
 	}
-	if ((icon = ::get_icon ("ardour_icon_32px")) != 0) {
+	if ((icon = ::get_icon ("ardour_icon_32px"))) {
 		window_icons.push_back (icon);
 	}
-	if ((icon = ::get_icon ("ardour_icon_48px")) != 0) {
+	if ((icon = ::get_icon ("ardour_icon_48px"))) {
 		window_icons.push_back (icon);
 	}
 	if (!window_icons.empty()) {
@@ -1862,8 +1862,7 @@ Editor::add_region_context_items (AudioStreamView* sv,
 		   become selected.
 		*/
 
-		region_menu->signal_map_event().connect (
-			bind (
+		region_menu->signal_map_event().connect ( bind (
 				mem_fun(*this, &Editor::set_selected_regionview_from_map_event), 
 				sv, 
 				boost::weak_ptr<Region>(region)
