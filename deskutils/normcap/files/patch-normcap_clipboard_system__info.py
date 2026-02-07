--- normcap/clipboard/system_info.py.orig	2024-05-07 18:10:18 UTC
+++ normcap/clipboard/system_info.py
@@ -10,7 +10,7 @@ def os_has_wayland_display_manager() -> bool:
 
 
 def os_has_wayland_display_manager() -> bool:
-    if sys.platform != "linux":
+    if sys.platform != "linux" and sys.platform != "freebsd":
         return False
 
     xdg_session_type = os.environ.get("XDG_SESSION_TYPE", "").lower()
@@ -19,7 +19,7 @@ def os_has_awesome_wm() -> bool:
 
 
 def os_has_awesome_wm() -> bool:
-    if sys.platform != "linux":
+    if sys.platform != "linux" and sys.platform != "freebsd":
         return False
 
     return "awesome" in os.environ.get("XDG_CURRENT_DESKTOP", "").lower()
@@ -36,7 +36,7 @@ def get_gnome_version() -> str:
     Returns:
         Version string or empty string if not detected.
     """
-    if sys.platform != "linux":
+    if sys.platform != "linux" and sys.platform != "freebsd":
         return ""
 
     if (
