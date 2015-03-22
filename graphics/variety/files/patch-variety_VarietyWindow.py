--- variety/VarietyWindow.py.orig	2015-03-07 10:46:27 UTC
+++ variety/VarietyWindow.py
@@ -2333,7 +2333,7 @@ To set a specific wallpaper: %prog /some
                 ("auto" if refresh_level == VarietyWindow.RefreshLevel.ALL else "refresh")
             logger.debug(lambda: "Running set_wallpaper script with parameters: %s, %s, %s" % (wallpaper, auto, original_file))
             try:
-                subprocess.check_call(["timeout", "--kill-after=5", "10", script, wallpaper, auto, original_file])
+                subprocess.check_call(["gtimeout", "--kill-after=5", "10", script, wallpaper, auto, original_file])
             except subprocess.CalledProcessError, e:
                 if e.returncode == 124:
                     logger.error(lambda: "Timeout while running set_wallpaper script, killed")
@@ -2695,7 +2695,7 @@ To set a specific wallpaper: %prog /some
                 "Name=Variety\n"
                 "Comment=Variety Wallpaper Changer\n"
                 "Icon=%s\n"
-                'Exec=sh -c "/opt/extras.ubuntu.com/variety/bin/variety || /usr/bin/variety || /opt/variety/bin/variety"\n'
+                'Exec=sh -c "%%PREFIX%%/bin/variety"\n'
                 "Terminal=false\n"
                 "Type=Application\n"
                 "X-GNOME-Autostart-Delay=20\n"
