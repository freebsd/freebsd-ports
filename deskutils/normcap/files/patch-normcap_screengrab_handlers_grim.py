--- normcap/screengrab/handlers/grim.py.orig	2024-05-08 15:26:52 UTC
+++ normcap/screengrab/handlers/grim.py
@@ -17,7 +17,7 @@ def is_compatible() -> bool:
 
 def is_compatible() -> bool:
     return (
-        sys.platform == "linux"
+        (sys.platform == "linux" or sys.platform == "freebsd")
         and system_info.has_wayland_display_manager()
         and system_info.has_wlroots_compositor()
     )
