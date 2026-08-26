Fix import failure with setuptools < 69.0 (setuptools.modified)

--- setuptools_gettext/__init__.py.orig	2026-08-12 19:21:26 UTC
+++ setuptools_gettext/__init__.py
@@ -28,7 +28,10 @@ from setuptools.errors import OptionError
 from setuptools import Command
 from setuptools.dist import Distribution
 from setuptools.errors import OptionError
-from setuptools.modified import newer
+try:
+    from setuptools.modified import newer
+except ImportError:  # setuptools < 69.0
+    from setuptools._distutils.dep_util import newer
 
 from .catalog import (
     LC_MESSAGES,
