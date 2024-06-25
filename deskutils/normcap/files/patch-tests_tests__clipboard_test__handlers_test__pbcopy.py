--- tests/tests_clipboard/test_handlers/test_pbcopy.py.orig	2024-05-08 15:30:34 UTC
+++ tests/tests_clipboard/test_handlers/test_pbcopy.py
@@ -13,6 +13,7 @@ from normcap.clipboard.handlers import pbcopy
         ("darwin", True),
         ("win32", False),
         ("linux", False),
+        ("freebsd", False),
     ],
 )
 def test_pbcopy_is_compatible(monkeypatch, platform, result):
