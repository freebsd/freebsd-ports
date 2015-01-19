--- setuptools/command/install_lib.py.orig	2014-07-05 18:05:55.000000000 +0200
+++ setuptools/command/install_lib.py	2014-07-20 21:06:16.000000000 +0200
@@ -1,5 +1,5 @@
 import distutils.command.install_lib as orig
-import os
+import os, imp
 
 
 class install_lib(orig.install_lib):
@@ -17,12 +17,24 @@
         nsp = self.distribution.namespace_packages
         svem = (nsp and self.get_finalized_command('install')
                 .single_version_externally_managed)
+        exclude_names = ['__init__.py', '__init__.pyc', '__init__.pyo']
+        if hasattr(imp, 'get_tag') :
+            exclude_names.extend((
+                os.path.join(
+                    '__pycache__',
+                    '__init__.' + imp.get_tag() + '.pyc'
+                ),
+                os.path.join(
+                    '__pycache__',
+                    '__init__.' + imp.get_tag() + '.pyo'
+                ),
+            ))
         if svem:
             for pkg in nsp:
                 parts = pkg.split('.')
                 while parts:
                     pkgdir = os.path.join(self.install_dir, *parts)
-                    for f in '__init__.py', '__init__.pyc', '__init__.pyo':
+                    for f in exclude_names :
                         exclude[os.path.join(pkgdir, f)] = 1
                     parts.pop()
         return exclude
