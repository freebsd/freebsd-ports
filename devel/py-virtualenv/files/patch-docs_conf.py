--- docs/conf.py.orig	2023-02-06 17:33:30 UTC
+++ docs/conf.py
@@ -3,6 +3,8 @@ import sys
 from datetime import date, datetime
 from pathlib import Path
 
+sys.path.insert(0, '%%VIRTUALENV_WHEEL%%')
+
 from virtualenv.version import __version__
 
 company = "PyPA"
@@ -48,7 +50,7 @@ extlinks = {
 def setup(app):
     here = Path(__file__).parent
     root, exe = here.parent, Path(sys.executable)
-    towncrier = exe.with_name(f"towncrier{exe.suffix}")
+    towncrier = exe.with_name(f"towncrier-%%PYTHON_VER%%")
     cmd = [str(towncrier), "build", "--draft", "--version", "NEXT"]
     new = subprocess.check_output(cmd, cwd=root, text=True, stderr=subprocess.DEVNULL)
     (root / "docs" / "_draft.rst").write_text("" if "No significant changes" in new else new)
