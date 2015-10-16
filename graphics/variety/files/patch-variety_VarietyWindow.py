--- variety/VarietyWindow.py.orig	2015-09-06 14:49:07 UTC
+++ variety/VarietyWindow.py
@@ -2339,7 +2339,7 @@ To set a specific wallpaper: %prog /some
                 ("auto" if refresh_level == VarietyWindow.RefreshLevel.ALL else "refresh")
             logger.debug(lambda: "Running set_wallpaper script with parameters: %s, %s, %s" % (wallpaper, auto, original_file))
             try:
-                subprocess.check_call(["timeout", "--kill-after=5", "10", script, wallpaper, auto, original_file])
+                subprocess.check_call(["gtimeout", "--kill-after=5", "10", script, wallpaper, auto, original_file])
             except subprocess.CalledProcessError, e:
                 if e.returncode == 124:
                     logger.error(lambda: "Timeout while running set_wallpaper script, killed")
