--- normcap/screengrab/handlers/qt.py.orig	2024-05-08 15:30:01 UTC
+++ normcap/screengrab/handlers/qt.py
@@ -11,7 +11,7 @@ def is_compatible() -> bool:
 
 
 def is_compatible() -> bool:
-    return sys.platform != "linux" or not system_info.has_wayland_display_manager()
+    return (sys.platform != "linux" and sys.platform != "freebsd") or not system_info.has_wayland_display_manager()
 
 
 def is_installed() -> bool:
