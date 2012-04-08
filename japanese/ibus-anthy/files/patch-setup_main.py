--- setup/main.py.orig	2012-04-08 17:47:23.692620971 +0900
+++ setup/main.py	2012-04-08 17:58:44.140619685 +0900
@@ -63,7 +63,7 @@
         # glade "icon_name" property has a custom scaling and it seems
         # to be difficult to show the complicated small icon in metacity.
         # This can add the pixbuf without scaling.
-        anthydir = path.dirname(path.dirname(__file__))
+        anthydir = "@@LOCALBASE@@/share/ibus-anthy"
         if not anthydir:
             anthydir = "/usr/share/ibus-anthy"
         icon_path = path.join(anthydir, "icons", "ibus-anthy.png")
