--- setup.py.orig	2024-02-04 06:12:50 UTC
+++ setup.py
@@ -3,6 +3,7 @@ from Cython.Build import cythonize
 import setuptools
 
 from Cython.Build import cythonize
+from build_cython import *
 
 init = (pathlib.Path('tree_sitter_languages') / '__init__.py').read_text()
 match = re.search(r"^__version__ = '(.+)'$", init, re.MULTILINE)
