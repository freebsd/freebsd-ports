--- tests/tests_gui/test_system_info.py.orig	2024-05-08 15:32:00 UTC
+++ tests/tests_gui/test_system_info.py
@@ -188,6 +188,7 @@ def test_config_directory_fallback(monkeypatch):
     ("platform", "binary", "directory"),
     [
         ("linux", "tesseract", "bin"),
+        ("freebsd", "tesseract", "bin"),
         ("win32", "tesseract.exe", "tesseract"),
         ("darwin", "tesseract", "bin"),
     ],
