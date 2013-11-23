From 7418b30d4e11f78cdb58c6d8afa67c5ddbb2f0d5 Mon Sep 17 00:00:00 2001
From: Stefano Karapetsas <stefano@karapetsas.com>
Date: Sat, 11 May 2013 20:48:47 +0000
Subject: gstreamer: Middle click on applet toggles mute state

---
diff --git a/gst-mixer-applet/applet.c b/gst-mixer-applet/applet.c
index 9ad53bb..1a511ed 100644
--- gst-mixer-applet/applet.c
+++ gst-mixer-applet/applet.c
@@ -827,7 +827,9 @@ mate_volume_applet_button (GtkWidget      *widget,
             break;
         }
         break;
-      case 2: /* move */
+      case 2: /* mute */
+        mate_volume_applet_toggle_mute (applet);
+        return TRUE;
       case 3: /* menu */
         if (applet->pop) {
           mate_volume_applet_popdown_dock (applet);
--
cgit 
