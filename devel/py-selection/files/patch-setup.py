--- setup.py.orig	2015-04-16 10:03:43 UTC
+++ setup.py
@@ -7,7 +7,7 @@ setup(
     author = 'Gregory Petukhov',
     author_email = 'lorien@lorien.name',
     install_requires = ['lxml', 'weblib', 'six'],
-    packages = ['selection', 'selection.backend', 'test'],
+    packages = ['selection', 'selection.backend'],
     license = "MIT",
     classifiers = (
         'Programming Language :: Python',
