x11-themes/gnome-backgrounds 44.x contains .webp images
x11-themes/gnome-backgrounds 45.x and higher contains .jxl images

--- gtweak/tweaks/tweak_group_appearance.py.orig	2024-04-26 06:06:48 UTC
+++ gtweak/tweaks/tweak_group_appearance.py
@@ -253,13 +253,13 @@ TWEAK_GROUP = TweakPreferencesPage("appearance", _("Ap
       _("Default Image"),
       "org.gnome.desktop.background",
       "picture-uri",
-      mimetypes=["application/xml", "image/png", "image/jpeg"],
+      mimetypes=["application/xml", "image/svg+xml", "image/png", "image/jpeg", "image/webp", "image/jxl"],
     ),
     GSettingsFileChooserButtonTweak(
       _("Dark Style Image"),
       "org.gnome.desktop.background",
       "picture-uri-dark",
-      mimetypes=["application/xml", "image/png", "image/jpeg"],
+      mimetypes=["application/xml", "image/svg+xml", "image/png", "image/jpeg", "image/webp", "image/jxl"],
     ),
     GSettingsTweakComboRow(
       _("Adjustment"), "org.gnome.desktop.background", "picture-options"
