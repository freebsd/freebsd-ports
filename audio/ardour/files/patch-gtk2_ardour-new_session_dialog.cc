--- gtk2_ardour/new_session_dialog.cc.orig	2008-01-14 10:04:17.000000000 +0100
+++ gtk2_ardour/new_session_dialog.cc	2008-01-14 10:04:44.000000000 +0100
@@ -361,16 +361,16 @@ NewSessionDialog::NewSessionDialog()
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
@@ -589,7 +589,7 @@ NewSessionDialog::set_session_folder(const std::string
 	*/
 
 
-#ifdef __APPLE__
+#ifndef __Linux__
 
 	char buf[PATH_MAX];
 
