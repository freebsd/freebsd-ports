--- libs/ardour/io.cc.orig	Thu Dec  7 12:58:12 2006
+++ libs/ardour/io.cc	Thu Dec  7 13:02:49 2006
@@ -2485,7 +2485,8 @@
 		} else {
 			// do falloff
 			new_peak = _visible_peak_power[n] - Config->get_meter_falloff();
-			_visible_peak_power[n] = max (new_peak, -INFINITY);
+			// libs/ardour/io.cc:2488: error: no matching function for call to `max(float&, double)'
+			_visible_peak_power[n] = max (new_peak, (float)-INFINITY);
 		}
 	}
 }
