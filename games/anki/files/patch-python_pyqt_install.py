Only import PIP if it's available otherwise continue as usual.

--- python/pyqt/install.py.orig	2022-06-26 10:33:56 UTC
+++ python/pyqt/install.py
@@ -6,7 +6,11 @@ import sys
 import subprocess
 import sys
 
-from pip._internal.commands import create_command
+try:
+    from pip._internal.commands import create_command
+    is_pip_available = True
+except:
+    is_pip_available = False
 
 
 def install_packages(requirements_path, directory, pip_args):
@@ -21,8 +25,10 @@ def install_packages(requirements_path, directory, pip
         "-r",
         requirements_path
     ] + pip_args
-    cmd = create_command("install")
-    assert not cmd.main(pip_args)
+
+    if is_pip_available:
+        cmd = create_command("install")
+        assert not cmd.main(pip_args)
 
 
 def main():
