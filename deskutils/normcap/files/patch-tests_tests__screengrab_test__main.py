--- tests/tests_screengrab/test_main.py.orig	2024-05-08 15:24:40 UTC
+++ tests/tests_screengrab/test_main.py
@@ -39,6 +39,14 @@ def test_capture(qapp):
         ("linux", "41.0", False, False, False, Handler.QT),
         ("linux", "40.0", True, False, False, Handler.DBUS_SHELL),
         ("linux", "40.0", False, False, False, Handler.QT),
+        ("freebsd", "", False, True, True, Handler.QT),
+        ("freebsd", "", True, True, True, Handler.GRIM),
+        ("freebsd", "", True, False, True, Handler.DBUS_PORTAL),
+        ("freebsd", "", True, False, False, Handler.DBUS_PORTAL),
+        ("freebsd", "41.0", True, False, False, Handler.DBUS_PORTAL),
+        ("freebsd", "41.0", False, False, False, Handler.QT),
+        ("freebsd", "40.0", True, False, False, Handler.DBUS_SHELL),
+        ("freebsd", "40.0", False, False, False, Handler.QT),
     ],
 )
 def test_get_available_handlers(
