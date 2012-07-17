--- lib/pypy1.9/distutils/sysconfig_pypy.py.orig	2012-07-13 22:52:04.000000000 +0200
+++ lib/pypy1.9/distutils/sysconfig_pypy.py	2012-07-13 22:58:35.000000000 +0200
@@ -15,7 +15,7 @@
 
 def get_python_inc(plat_specific=0, prefix=None):
     from os.path import join as j
-    return j(sys.prefix, 'include')
+    return j(sys.prefix, 'include', 'pypy' + sys.version[-6:-3])
 
 def get_python_version():
     """Return a string containing the major and minor Python version,
@@ -44,7 +44,7 @@
             "calls to get_python_lib(standard_lib=1) cannot succeed")
     if prefix is None:
         prefix = PREFIX
-    return os.path.join(prefix, 'site-packages')
+    return os.path.join(prefix, 'lib', 'pypy' + sys.version[-6:-3], 'site-packages')
 
 
 _config_vars = None
