--- normcap/screengrab/permissions.py.orig	2024-01-22 09:18:58 UTC
+++ normcap/screengrab/permissions.py
@@ -225,9 +225,9 @@ def has_screenshot_permission() -> bool:
     logger.debug("Checking screenshot permission")
     if sys.platform == "darwin":
         return _macos_has_screenshot_permission()
-    if sys.platform == "linux" and not utils.is_wayland_display_manager():
+    if (sys.platform == "linux" or sys.platform.startswith("freebsd")) and not utils.is_wayland_display_manager():
         return True
-    if sys.platform == "linux" and utils.is_wayland_display_manager():
+    if (sys.platform == "linux" or sys.platform.startswith("freebsd")) and utils.is_wayland_display_manager():
         return _dbus_portal_has_screenshot_permission()
     if sys.platform == "win32":
         return True
@@ -245,14 +245,14 @@ def request_screenshot_permission(
         )
         return
 
-    if sys.platform == "linux" and not utils.is_wayland_display_manager():
+    if (sys.platform == "linux" or sys.platform.startswith("freebsd")) and not utils.is_wayland_display_manager():
         logger.debug(
             "Not necessary to request screenshot permission on Linux, if the "
             "display manager is not Wayland. Skipping."
         )
         return
 
-    if sys.platform == "linux" and utils.is_wayland_display_manager():
+    if (sys.platform == "linux" or sys.platform.startswith("freebsd")) and utils.is_wayland_display_manager():
         logger.debug("Show request permission dialog.")
         dbus_portal_show_request_permission_dialog(
             title=dialog_title, text=linux_dialog_text
