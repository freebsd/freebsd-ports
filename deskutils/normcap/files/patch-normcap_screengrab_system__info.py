--- normcap/screengrab/system_info.py.orig	2024-05-08 15:07:15 UTC
+++ normcap/screengrab/system_info.py
@@ -15,7 +15,7 @@ def has_wlroots_compositor() -> bool:
     Certainly not wlroots based are: KDE, GNOME and Unity.
     Others are likely wlroots based.
     """
-    if sys.platform != "linux":
+    if sys.platform != "linux" and sys.platform != "freebsd":
         return False
 
     kde_full_session = os.environ.get("KDE_FULL_SESSION", "").lower()
@@ -39,7 +39,7 @@ def has_wayland_display_manager() -> bool:
 
 def has_wayland_display_manager() -> bool:
     """Identify relevant display managers (Linux)."""
-    if sys.platform != "linux":
+    if sys.platform != "linux" and sys.platform != "freebsd":
         return False
 
     xdg_session_type = os.environ.get("XDG_SESSION_TYPE", "").lower()
@@ -54,7 +54,7 @@ def get_gnome_version() -> str:
     Returns:
         Version string or empty string if not detected.
     """
-    if sys.platform != "linux":
+    if sys.platform != "linux" and sys.platform != "freebsd":
         return ""
 
     if (
