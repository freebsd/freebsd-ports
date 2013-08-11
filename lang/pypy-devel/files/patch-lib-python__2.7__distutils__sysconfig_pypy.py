--- lib-python/2.7/distutils/sysconfig_pypy.py.orig	2012-11-22 14:52:20.000000000 +0200
+++ lib-python/2.7/distutils/sysconfig_pypy.py	2012-11-27 17:59:44.000000000 +0200
@@ -15,7 +15,7 @@
 
 def get_python_inc(plat_specific=0, prefix=None):
     from os.path import join as j
-    return j(sys.prefix, 'include')
+    return j(sys.prefix, 'include', 'pypy-%s.%s' % sys.pypy_version_info[:2])
 
 def get_python_version():
     """Return a string containing the major and minor Python version,
@@ -42,8 +42,8 @@
     if prefix is None:
         prefix = PREFIX
     if standard_lib:
-        return os.path.join(prefix, "lib-python", get_python_version())
-    return os.path.join(prefix, 'site-packages')
+        return os.path.join(prefix, 'lib', 'pypy-%s.%s' % sys.pypy_version_info[:2])
+    return os.path.join(prefix, 'lib', 'pypy-%s.%s' % sys.pypy_version_info[:2], 'site-packages')
 
 
 _config_vars = None
