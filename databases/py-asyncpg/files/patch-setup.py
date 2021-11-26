--- setup.py.orig	2021-11-16 22:38:59 UTC
+++ setup.py
@@ -25,7 +25,7 @@ from setuptools.command import sdist as setuptools_sdi
 from setuptools.command import build_ext as setuptools_build_ext
 
 
-CYTHON_DEPENDENCY = 'Cython(>=0.29.24,<0.30.0)'
+CYTHON_DEPENDENCY = 'Cython(>=0.29.24)'
 
 # Minimal dependencies required to test asyncpg.
 TEST_DEPENDENCIES = [
