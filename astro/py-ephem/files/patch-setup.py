--- setup.py.orig	2019-08-17 17:39:14 UTC
+++ setup.py
@@ -1,4 +1,13 @@
+# Currently ephem fails if the text files contain unicode characters.
+# To fix this we need to open the files as utf-8 explicitly.
+# Since open() in Python 2 doesn't support an encoding parameter,
+# TODO: Upstream
+#
+# Add setup.py test command support to run tests
+# TODO: Upstream
+
 import os
+import io
 import sys
 from distutils.core import setup, Extension
 from glob import glob
@@ -24,7 +33,7 @@ libastro_files = glob('libastro-%s/*.c' % libastro_ver
 libastro_data = glob('extensions/data/*.c')
 
 def read(*filenames):
-    return open(os.path.join(os.path.dirname(__file__), *filenames)).read()
+    return io.open(os.path.join(os.path.dirname(__file__), *filenames), encoding="utf-8").read()
 
 extensions = [
     Extension('ephem._libastro',
@@ -62,4 +71,5 @@ setup(name = 'ephem',
                                  'tests/usno/*.txt',
                                  ],},
       ext_modules = extensions,
+      test_suite='ephem.tests',
       )
