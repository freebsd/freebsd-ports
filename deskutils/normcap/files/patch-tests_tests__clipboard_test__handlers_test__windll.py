--- tests/tests_clipboard/test_handlers/test_windll.py.orig	2024-05-08 15:34:16 UTC
+++ tests/tests_clipboard/test_handlers/test_windll.py
@@ -29,7 +29,7 @@ def clipboard_blocked():
 
 
 @pytest.mark.parametrize(
-    ("platform", "result"), [("win32", True), ("darwin", False), ("linux", False)]
+    ("platform", "result"), [("win32", True), ("darwin", False), ("linux", False), ("freebsd", False)]
 )
 def test_windll_is_compatible(monkeypatch, platform, result):
     monkeypatch.setattr(windll.sys, "platform", platform)
