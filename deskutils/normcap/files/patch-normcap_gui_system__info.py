--- normcap/gui/system_info.py.orig	2024-05-08 15:35:35 UTC
+++ normcap/gui/system_info.py
@@ -73,7 +73,7 @@ def get_tesseract_path() -> Path:
         RuntimeError: If the Tesseract binary cannot be located.
     """
     if is_briefcase_package():
-        if sys.platform == "linux":
+        if sys.platform == "linux" or sys.platform == "freebsd":
             binary_path = Path(__file__).parent.parent.parent.parent / "bin"
         elif sys.platform == "win32":
             binary_path = Path(__file__).parent.parent / "resources" / "tesseract"
