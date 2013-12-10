--- lib-python/2.7/distutils/command/install.py.orig	2012-07-15 10:10:18.000000000 +0200
+++ lib-python/2.7/distutils/command/install.py	2012-07-15 10:13:15.000000000 +0200
@@ -84,9 +84,9 @@
         'data'   : '$userbase',
         },
     'pypy': {
-        'purelib': '$base/site-packages',
-        'platlib': '$base/site-packages',
-        'headers': '$base/include',
+        'purelib': '$base/lib/pypy-$pypy_version_short/site-packages',
+        'platlib': '$platbase/lib/pypy-$pypy_version_short/site-packages',
+        'headers': '$base/include/pypy-$pypy_version_short/$dist_name',
         'scripts': '$base/bin',
         'data'   : '$base',
         },
@@ -304,6 +304,7 @@
         # about needing recursive variable expansion (shudder).
 
         py_version = (string.split(sys.version))[0]
+        pypy_version = '%s.%s.%s' % sys.pypy_version_info[:3]
         (prefix, exec_prefix) = get_config_vars('prefix', 'exec_prefix')
         self.config_vars = {'dist_name': self.distribution.get_name(),
                             'dist_version': self.distribution.get_version(),
@@ -311,6 +312,9 @@
                             'py_version': py_version,
                             'py_version_short': py_version[0:3],
                             'py_version_nodot': py_version[0] + py_version[2],
+                            'pypy_version': pypy_version,
+                            'pypy_version_short': pypy_version[0:3],
+                            'pypy_version_nodot': pypy_version[0] + pypy_version[2],
                             'sys_prefix': prefix,
                             'prefix': prefix,
                             'sys_exec_prefix': exec_prefix,
