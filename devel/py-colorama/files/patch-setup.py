Default to UTF-8 encoding to fix build with Python 3.6

Obtained from: https://github.com/tartley/colorama/pull/294/files

--- setup.py.orig	2020-10-12 21:22:32 UTC
+++ setup.py
@@ -3,6 +3,7 @@
 
 from __future__ import with_statement
 
+from io import open
 import os
 import re
 try:
@@ -14,8 +15,9 @@ except ImportError:
 NAME = 'colorama'
 
 
-def read_file(path):
-    with open(os.path.join(os.path.dirname(__file__), path)) as fp:
+def read_file(path, encoding='utf8'):
+    with open(os.path.join(os.path.dirname(__file__), path),
+              encoding=encoding) as fp:
         return fp.read()
 
 def _get_version_match(content):
