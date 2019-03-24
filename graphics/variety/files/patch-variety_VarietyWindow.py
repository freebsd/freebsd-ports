--- variety/VarietyWindow.py.orig	2018-10-23 15:56:25 UTC
+++ variety/VarietyWindow.py
@@ -2351,7 +2351,7 @@ To set a specific wallpaper: %prog /some/local/image.j
                 ("auto" if refresh_level == VarietyWindow.RefreshLevel.ALL else "refresh")
             logger.debug(lambda: "Running set_wallpaper script with parameters: %s, %s, %s" % (wallpaper, auto, original_file))
             try:
-                subprocess.check_call(["timeout", "--kill-after=5", "10", script, wallpaper, auto, original_file])
+                subprocess.check_call(["gtimeout", "--kill-after=5", "10", script, wallpaper, auto, original_file])
             except subprocess.CalledProcessError as e:
                 if e.returncode == 124:
                     logger.error(lambda: "Timeout while running set_wallpaper script, killed")
