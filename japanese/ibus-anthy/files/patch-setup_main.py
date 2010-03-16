--- setup/main.py.orig	2010-03-16 17:32:17.110533466 +0900
+++ setup/main.py	2010-03-16 17:33:17.660764012 +0900
@@ -59,7 +59,7 @@
         # This can add the pixbuf without scaling.
         anthydir = path.dirname(path.dirname(__file__))
         if not anthydir:
-            anthydir = "/usr/share/ibus-anthy"
+            anthydir = "@@LOCALBASE@@/share/ibus-anthy"
         icon_path = path.join(anthydir, "icons", "ibus-anthy.png")
         if path.exists(icon_path):
             xml.get_widget('main').set_icon_from_file(icon_path)
