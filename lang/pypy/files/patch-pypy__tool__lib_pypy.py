--- pypy/tool/lib_pypy.py.orig	2012-06-07 14:24:48.000000000 +0200
+++ pypy/tool/lib_pypy.py	2012-06-22 14:46:42.000000000 +0200
@@ -1,12 +1,11 @@
 import py
 import pypy
 import pypy.module
-from pypy.module.sys.version import CPYTHON_VERSION
+from pypy.module.sys.version import PYPY_VERSION
 
 LIB_ROOT = py.path.local(pypy.__path__[0]).dirpath()
-LIB_PYPY =  LIB_ROOT.join('lib_pypy')
-LIB_PYTHON = LIB_ROOT.join('lib-python', '%d.%d' % CPYTHON_VERSION[:2])
-
+LIB_PYTHON =  LIB_ROOT.join('lib', 'pypy-%d.%d' % PYPY_VERSION[:2])
+LIB_PYPY = LIB_PYTHON.join('lib_pypy')
 
 def import_from_lib_pypy(modname):
     modname = LIB_PYPY.join(modname+'.py')
