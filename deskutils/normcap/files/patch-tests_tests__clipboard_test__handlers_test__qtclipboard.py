--- tests/tests_clipboard/test_handlers/test_qtclipboard.py.orig	2024-05-08 15:38:08 UTC
+++ tests/tests_clipboard/test_handlers/test_qtclipboard.py
@@ -18,6 +18,8 @@ real_import = builtins.__import__
         ("win32", "wayland", True),
         ("linux", "", True),
         ("linux", "wayland", False),
+        ("freebsd", "", True),
+        ("freebsd", "wayland", False),
     ],
 )
 def test_qtclipboard_is_compatible(monkeypatch, platform, wayland_display, result):
