--- setup.py.orig	2017-12-16 21:08:32.634424000 -0300
+++ setup.py	2017-12-16 21:10:59.767507000 -0300
@@ -57,7 +57,10 @@
 
 
 def get_long_description():
-    lines = open('README.rst', 'rb').read().splitlines(False)
+    if sys.version_info[0] > 2:
+        lines = open('README.rst', encoding='utf-8').read().splitlines(False)
+    else:
+        lines = open('README.rst').read().splitlines(False)
     end = lines.index(b'Getting Started')
     return '\n' + str(b'\n'.join(lines[:end])) + '\n'
