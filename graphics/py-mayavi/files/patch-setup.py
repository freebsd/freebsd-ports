-- Work around the old setuptools port (<=70) which does not provide
-- setuptools.command.bdist_wheel; fall back to wheel.bdist_wheel instead.
-- This allows building without upgrading devel/py-setuptools.
--- setup.py.orig	2026-09-21 18:18:49 UTC
+++ setup.py
@@ -4,9 +4,12 @@ from setuptools import Command, Distribution, setup
 # All rights reserved.
 
 from setuptools import Command, Distribution, setup
-from setuptools.command.bdist_wheel import bdist_wheel
 from setuptools.command.build_py import build_py
 from setuptools.command.develop import develop
+try:
+    from setuptools.command.bdist_wheel import bdist_wheel
+except ModuleNotFoundError:
+    from wheel.bdist_wheel import bdist_wheel
 
 import os
 import sys
