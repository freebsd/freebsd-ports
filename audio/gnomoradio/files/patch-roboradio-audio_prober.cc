--- roboradio/audio/prober.cc.orig	2007-12-06 15:39:58.000000000 +0100
+++ roboradio/audio/prober.cc	2007-12-06 15:40:19.000000000 +0100
@@ -21,6 +21,30 @@
 #include "../mp3/esd-audio.h"
 }
 
+namespace Roboradio
+{
+   namespace Audio
+   {
+      gboolean probe (gpointer s)
+      {
+         Prober *sng = static_cast<Prober*>(s);
+         if (esdout_playing()) {
+            int pos = sng->get_position();
+            if (pos >= 0)
+               sng->signal_position_changed(pos);
+            return true;
+         } else if (sng->get_position() >= 0) {
+            return true;
+         } else {
+            sng->stop();
+            sng->signal_done();
+            sng->activated = false;
+            return false;
+         }
+      }
+   }
+}
+
 Roboradio::Audio::Prober::Prober ()
 	: activated(false)
 {
@@ -31,24 +55,6 @@
 	stop_prober();
 }
 
-gboolean Roboradio::Audio::probe (gpointer s)
-{
-	Prober *sng = static_cast<Prober*>(s);
-	if (esdout_playing()) {
-		int pos = sng->get_position();
-		if (pos >= 0)
-			sng->signal_position_changed(pos);
-		return true;
-	} else if (sng->get_position() >= 0) {
-		return true;
-	} else {
-		sng->stop();
-		sng->signal_done();
-		sng->activated = false;
-		return false;
-	}
-}
-
 void Roboradio::Audio::Prober::start_prober ()
 {
 	if (activated)
