--- pypy/module/sys/initpath.py.orig	2012-11-27 18:15:02.000000000 +0200
+++ pypy/module/sys/initpath.py	2012-11-27 18:19:45.000000000 +0200
@@ -90,14 +90,13 @@
     least contain a directory called ``lib-python/X.Y`` and another one called
     ``lib_pypy``. If they cannot be found, it raises OSError.
     """
-    from pypy.module.sys.version import CPYTHON_VERSION
-    dirname = '%d.%d' % (CPYTHON_VERSION[0],
-                         CPYTHON_VERSION[1])
-    lib_python = os.path.join(prefix, 'lib-python')
+    from pypy.module.sys.version import PYPY_VERSION
+    dirname = 'pypy%d.%d' % PYPY_VERSION[:2]
+    lib_python = os.path.join(prefix, 'lib')
     python_std_lib = os.path.join(lib_python, dirname)
     _checkdir(python_std_lib)
 
-    lib_pypy = os.path.join(prefix, 'lib_pypy')
+    lib_pypy = os.path.join(python_std_lib, 'lib_pypy')
     _checkdir(lib_pypy)
 
     importlist = []
