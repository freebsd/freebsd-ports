--- /dev/null	2008-06-11 11:33:00.000000000 +0400
+++ setup.py	2008-06-11 11:38:41.000000000 +0400
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
+    version = "0.11.0",
+    description = "A frontend for dynamips",
+    author = "Greg Anuzelli",
+    author_email = "dynagen@gmail.com",
+    url = "http://sourceforge.net/projects/dyna-gen",
+
+    py_modules = ['confConsole','configobj','console','dynamips_lib',
+	'pemu_lib', 'pemubin', 'pemuwrapper',
+	'validate']
+)
+
+print "If you have installed the modules, copy dynagen to some "
+print "place in your $PATH, like /usr/local/bin/."
