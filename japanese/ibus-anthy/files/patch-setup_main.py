--- setup/main.py.orig	2012-04-02 08:48:25.111727456 +0900
+++ setup/main.py	2012-04-02 08:51:09.382726912 +0900
@@ -71,7 +71,7 @@
         # glade 'icon_name' property has a custom scaling and it seems
         # to be difficult to show the complicated small icon in metacity.
         # This can add the pixbuf without scaling.
-        anthydir = path.dirname(path.dirname(__file__))
+        anthydir = "@@LOCALBASE@@/share/ibus-anthy"
         if not anthydir:
             anthydir = '/usr/share/ibus-anthy'
         icon_path = path.join(anthydir, 'icons', 'ibus-anthy.png')
