--- setup.py.orig	2019-02-11 06:36:33 UTC
+++ setup.py
@@ -8,8 +8,8 @@ except ImportError:
 
 import xmltodict
 
-with open('README.md') as f:
-    long_description = f.read()
+with open('README.md', 'rb') as f:
+    long_description = f.read().decode('utf-8')
 
 
 setup(name='xmltodict',
