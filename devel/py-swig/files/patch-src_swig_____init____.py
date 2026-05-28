-- Replace the bundled swig binary lookup with a call to the system swig
-- installed by devel/swig. This avoids duplicating the swig binary and
-- instead provides a thin Python wrapper around the installed system swig.

--- src/swig/__init__.py.orig	2026-05-27 20:12:44 UTC
+++ src/swig/__init__.py
@@ -1,23 +1,15 @@
-import os
-import platform
 import subprocess
 import sys
-import glob
+import shutil
 from ._version import __version__, __version_tuple__
 
-DATA = os.path.join(os.path.dirname(__file__), "data")
 
-BIN_DIR = os.path.join(DATA, "bin")
-SWIG_SHARE_DIR = os.path.join(DATA, "share" + os.path.sep + "swig")
-
-# should only be one swig_lib version in the data subfolder
-# make nicer if swig adds support for custom SWIG_LIB paths or relative swig_lib paths
-SWIG_LIB_ENV = os.environ
-SWIG_LIB_ENV["SWIG_LIB"] = glob.glob(SWIG_SHARE_DIR + os.path.sep + "*")[0]
-
-
 def _program(name, args):
-    return subprocess.call([os.path.join(BIN_DIR, name)] + args, env=SWIG_LIB_ENV)
+    swig_path = shutil.which(name)
+    if swig_path is None:
+        print(f"swig: {name}: command not found", file=sys.stderr)
+        return 1
+    return subprocess.call([swig_path] + args)
 
 
 def swig():
