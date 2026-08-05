--- astropy_helpers/utils.py.orig	2026-08-05 00:59:43 UTC
+++ astropy_helpers/utils.py
@@ -1,7 +1,7 @@ import contextlib
 # Licensed under a 3-clause BSD style license - see LICENSE.rst
 
 import contextlib
-import imp
+import importlib
 import os
 import sys
 import glob
@@ -54,9 +54,8 @@ def get_numpy_include_path():
     import builtins
     if hasattr(builtins, '__NUMPY_SETUP__'):
         del builtins.__NUMPY_SETUP__
-    import imp
     import numpy
-    imp.reload(numpy)
+    impportlib.reload(numpy)
 
     try:
         numpy_include = numpy.get_include()
