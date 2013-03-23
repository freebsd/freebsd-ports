--- lib/pypy2.0/lib_pypy/ctypes_config_cache/rebuild.py~	2012-06-22 11:42:55.000000000 +0200
+++ lib/pypy2.0/lib_pypy/ctypes_config_cache/rebuild.py	2012-06-22 11:43:12.000000000 +0200
@@ -6,7 +6,7 @@
 # get the correct path
 import os.path
 this_dir = os.path.dirname(__file__)
-autopath_py = os.path.join(this_dir, '../../pypy/tool/autopath.py')
+autopath_py = os.path.join(this_dir, '../../../../pypy/tool/autopath.py')
 autopath_py = os.path.abspath(autopath_py)
 execfile(autopath_py, dict(__name__='autopath', __file__=autopath_py))
 
