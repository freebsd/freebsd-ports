--- setup/main.py.orig	2012-01-14 12:14:14.986154797 +0900
+++ setup/main.py	2012-01-14 12:24:25.953154304 +0900
@@ -58,7 +58,7 @@
         # glade "icon_name" property has a custom scaling and it seems
         # to be difficult to show the complicated small icon in metacity.
         # This can add the pixbuf without scaling.
-        anthydir = path.dirname(path.dirname(__file__))
+        anthydir = "@@LOCALBASE@@/share/ibus-anthy"
         if not anthydir:
             anthydir = "/usr/share/ibus-anthy"
         icon_path = path.join(anthydir, "icons", "ibus-anthy.png")
