-- Allow the setuptools plugin to import bdist_wheel from the wheel package
-- when the installed setuptools version does not provide it.
--- src/python_sbom/setuptools.py.orig	2026-11-10 00:29:49 UTC
+++ src/python_sbom/setuptools.py
@@ -6,7 +6,14 @@ from typing import TYPE_CHECKING
 from pathlib import Path
 from typing import TYPE_CHECKING
 
-from setuptools.command.bdist_wheel import bdist_wheel
+try:
+    from setuptools.command.bdist_wheel import bdist_wheel
+except ModuleNotFoundError:
+    import warnings
+
+    with warnings.catch_warnings():
+        warnings.simplefilter("ignore", FutureWarning)
+        from wheel.bdist_wheel import bdist_wheel
 from setuptools.command.sdist import sdist
 
 from ._collect._revision import REVISION_FILE, default_revision, revision_record
