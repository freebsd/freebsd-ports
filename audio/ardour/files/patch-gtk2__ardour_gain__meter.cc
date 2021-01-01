--- gtk2_ardour/gain_meter.cc.orig	2010-04-20 17:28:37 UTC
+++ gtk2_ardour/gain_meter.cc
@@ -63,7 +63,7 @@ Glib::RefPtr<Gdk::Pixbuf> GainMeter::slider;
 void
 GainMeter::setup_slider_pix ()
 {
-	if ((slider = ::get_icon ("fader_belt")) == 0) {
+	if (!(slider = ::get_icon ("fader_belt"))) {
 		throw failed_constructor();
 	}
 }
@@ -89,11 +89,11 @@ GainMeterBase::GainMeterBase (Session& s, 
 	if (horizontal) {
 		gain_slider = manage (new HSliderController (pix,
 							     &gain_adjustment,
-							     false));
+							     0x0));
 	} else {
 		gain_slider = manage (new VSliderController (pix,
 							     &gain_adjustment,
-							     false));
+							     0x0));
 	}
 
 	level_meter = new LevelMeter(_session);
