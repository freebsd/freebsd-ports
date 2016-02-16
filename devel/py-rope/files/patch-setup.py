--- setup.py.orig	2015-08-06 05:38:27 UTC
+++ setup.py
@@ -42,7 +42,10 @@ classifiers = [
 
 
 def get_long_description():
-    lines = open('README.rst').read().splitlines(False)
+    if sys.version_info[0] > 2:
+        lines = open('README.rst', encoding='utf-8').read().splitlines(False)
+    else:
+        lines = open('README.rst').read().splitlines(False)
     end = lines.index('Getting Started')
     return '\n' + '\n'.join(lines[:end]) + '\n'
 
