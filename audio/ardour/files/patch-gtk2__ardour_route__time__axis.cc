--- gtk2_ardour/route_time_axis.cc.orig	2010-04-17 15:23:01 UTC
+++ gtk2_ardour/route_time_axis.cc
@@ -89,7 +89,7 @@ Glib::RefPtr<Gdk::Pixbuf> RouteTimeAxisView::slider;
 void
 RouteTimeAxisView::setup_slider_pix ()
 {
-	if ((slider = ::get_icon ("fader_belt_h")) == 0) {
+	if (!(slider = ::get_icon ("fader_belt_h"))) {
 		throw failed_constructor ();
 	}
 }
