--- pypy/module/sys/state.py.orig	2012-06-07 14:24:48.000000000 +0200
+++ pypy/module/sys/state.py	2012-06-22 14:45:23.000000000 +0200
@@ -36,14 +36,12 @@
 platform = sys.platform
 
 def getinitialpath(state, prefix):
-    from pypy.module.sys.version import CPYTHON_VERSION
-    dirname = '%d.%d' % (CPYTHON_VERSION[0],
-                         CPYTHON_VERSION[1])
-    lib_python = os.path.join(prefix, 'lib-python')
-    python_std_lib = os.path.join(lib_python, dirname)
+    from pypy.module.sys.version import PYPY_VERSION
+    libpath = os.path.join(prefix, 'lib')
+    python_std_lib = os.path.join(libpath, 'pypy%d.%d' % PYPY_VERSION[:2])
     checkdir(python_std_lib)
     
-    lib_pypy = os.path.join(prefix, 'lib_pypy')
+    lib_pypy = os.path.join(python_std_lib, 'lib_pypy')
     checkdir(lib_pypy)
 
     importlist = []
