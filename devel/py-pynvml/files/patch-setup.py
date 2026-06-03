--- setup.py.orig	2026-04-12 03:48:08 UTC
+++ setup.py
@@ -5,7 +5,16 @@ from setuptools.command.build_py import build_py
 
 from setuptools import setup
 from setuptools.command.build_py import build_py
-from setuptools.command.editable_wheel import editable_wheel, _TopLevelFinder
+
+try:
+    from setuptools.command.editable_wheel import editable_wheel, _TopLevelFinder
+except ImportError:
+    # Editable installs are not needed for wheel builds.
+    class _TopLevelFinder:
+        pass
+
+    class editable_wheel:
+        pass
 
 REDIRECTOR_PTH = "_pynvml_redirector.pth"
 REDIRECTOR_PY = "_pynvml_redirector.py"
