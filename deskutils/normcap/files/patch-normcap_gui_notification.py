--- normcap/gui/notification.py.orig	2024-05-08 15:11:11 UTC
+++ normcap/gui/notification.py
@@ -103,7 +103,7 @@ class Notifier(QtCore.QObject):
     def _send_notification(self, capture: Capture) -> None:
         """Show tray icon then send notification."""
         title, message = self._compose_notification(capture)
-        if sys.platform == "linux" and shutil.which("notify-send"):
+        if (sys.platform == "linux" or sys.platform == "freebsd") and shutil.which("notify-send"):
             self._send_via_libnotify(title=title, message=message)
         else:
             self._send_via_qt_tray(
