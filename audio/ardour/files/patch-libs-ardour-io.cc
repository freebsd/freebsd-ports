--- libs/ardour/io.cc.orig	Thu Jan  4 22:40:34 2007
+++ libs/ardour/io.cc	Thu Jan  4 22:41:09 2007
@@ -2498,7 +2498,7 @@
 		} else {
 			// do falloff, the config value is in dB/sec, we get updated at 100/sec currently (should be a var somewhere)
 			new_peak = _visible_peak_power[n] - (Config->get_meter_falloff() * 0.01f);
-			_visible_peak_power[n] = max (new_peak, -INFINITY);
+			_visible_peak_power[n] = max ((double)new_peak, -INFINITY);
 		}
 	}
 }
