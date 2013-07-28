--- lib/pypy2.1/lib_pypy/ctypes_config_cache/rebuild.py.orig	2013-04-08 15:26:29.000000000 +0200
+++ lib/pypy2.1/lib_pypy/ctypes_config_cache/rebuild.py	2013-05-06 20:32:36.000000000 +0200
@@ -3,7 +3,7 @@
 
 import os, sys
 
-sys.path.insert(0, os.path.realpath(os.path.join(os.path.dirname(__file__), '..', '..')))
+sys.path.insert(0, os.path.realpath(os.path.join(os.path.dirname(__file__), '..', '..')))
 
 import py
 
