--- lib-python/2.7/sysconfig.py.orig	2012-07-15 09:57:14.000000000 +0200
+++ lib-python/2.7/sysconfig.py	2012-07-15 10:03:25.000000000 +0200
@@ -27,12 +27,12 @@
         'data'   : '{base}',
         },
     'pypy': {
-        'stdlib': '{base}/lib-python/{py_version_short}',
-        'platstdlib': '{base}/lib-python/{py_version_short}',
-        'purelib': '{base}/lib-python/{py_version_short}',
-        'platlib': '{base}/lib-python/{py_version_short}',
-        'include': '{base}/include',
-        'platinclude': '{base}/include',
+        'stdlib': '{base}/lib/pypy-{pypy_version_short}',
+        'platstdlib': '{platbase}/lib/pypy-{pypy_version_short}',
+        'purelib': '{base}/lib/pypy-{pypy_version_short}/site-packages',
+        'platlib': '{platbase}/lib/pypy-{pypy_version_short}/site-packages',
+        'include': '{base}/include/pypy-{pypy_version_short}',
+        'platinclude': '{platbase}/include/pypy-{pypy_version_short}',
         'scripts': '{base}/bin',
         'data'   : '{base}',
         },
@@ -98,6 +98,8 @@
                 'scripts', 'data')
 _PY_VERSION = sys.version.split()[0]
 _PY_VERSION_SHORT = sys.version[:3]
+_PYPY_VERSION = '%s.%s.%s' % sys.pypy_version_info[:3]
+_PYPY_VERSION_SHORT = _PYPY_VERSION[:3]
 _PY_VERSION_SHORT_NO_DOT = _PY_VERSION[0] + _PY_VERSION[2]
 _PREFIX = os.path.normpath(sys.prefix)
 _EXEC_PREFIX = os.path.normpath(sys.exec_prefix)
@@ -304,6 +306,9 @@
         _CONFIG_VARS['py_version'] = _PY_VERSION
         _CONFIG_VARS['py_version_short'] = _PY_VERSION_SHORT
         _CONFIG_VARS['py_version_nodot'] = _PY_VERSION[0] + _PY_VERSION[2]
+        _CONFIG_VARS['pypy_version'] = _PYPY_VERSION
+        _CONFIG_VARS['pypy_version_short'] = _PYPY_VERSION_SHORT
+        _CONFIG_VARS['pypy_version_nodot'] = _PYPY_VERSION[0] + _PYPY_VERSION[2]
         _CONFIG_VARS['base'] = _PREFIX
         _CONFIG_VARS['platbase'] = _EXEC_PREFIX
         _CONFIG_VARS['projectbase'] = _PROJECT_BASE
