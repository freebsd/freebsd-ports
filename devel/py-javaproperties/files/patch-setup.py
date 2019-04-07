--- setup.py.orig	2018-05-25 22:39:16 UTC
+++ setup.py
@@ -3,6 +3,9 @@ import re
 from   setuptools import setup
 
 with open(join(dirname(__file__), 'javaproperties', '__init__.py')) as fp:
+    # Workaround for Python 3:
+    # Move a bit forward to get past the unicode characters
+    fp.seek(256)
     for line in fp:
         m = re.search(r'^\s*__version__\s*=\s*([\'"])([^\'"]+)\1\s*$', line)
         if m:
