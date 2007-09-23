--- /dev/null	Sat Nov 25 10:03:22 2006
+++ setup.py	Wed Oct 11 02:08:24 2006
@@ -0,0 +1,22 @@
+#!/usr/bin/env python
+
+"""Setup script for the dynagen module distribution."""
+# run this like python setup --root=/usr/local
+
+from distutils.core import setup, Extension
+
+setup( # Distribution meta-data
+    name = "dynagen",
+    version = "0.4.4",
+    description = "A frontend for dynamips",
+    author = "Greg Anuzelli",
+    author_email = "dynagen@gmail.com",
+    url = "http://sourceforge.net/projects/dyna-gen",
+
+    #py_modules = [ 'console', 'dynamips_lib']
+    py_modules = [ 'configobj', 'console', 'dynamips_lib',
+       'validate']
+)
+
+print "If you have installed the modules, copy dynagen to some "
+print "place in your $PATH, like /usr/local/bin/."
