--- lib/pypy1.9/site.py.orig	2012-06-07 14:24:48.000000000 +0200
+++ lib/pypy1.9/site.py	2012-06-22 15:47:31.000000000 +0200
@@ -302,13 +302,9 @@
 
         if sys.platform in ('os2emx', 'riscos'):
             sitepackages.append(os.path.join(prefix, "Lib", "site-packages"))
-        elif is_pypy:
-            from distutils.sysconfig import get_python_lib
-            sitedir = get_python_lib(standard_lib=False, prefix=prefix)
-            sitepackages.append(sitedir)
         elif os.sep == '/':
             sitepackages.append(os.path.join(prefix, "lib",
-                                        "python" + sys.version[:3],
+                                        "pypy" + sys.version[:3],
                                         "site-packages"))
             sitepackages.append(os.path.join(prefix, "lib", "site-python"))
         else:
