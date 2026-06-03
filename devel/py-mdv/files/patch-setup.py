--- setup.py.orig	2021-06-18 00:34:33 UTC
+++ setup.py
@@ -26,7 +26,7 @@ setup(
 setup(
     name='mdv',
     version=version,
-    packages=find_packages(),
+    packages=find_packages(exclude=("tests", "tests.*")), 
     author='Axiros GmbH',
     author_email='gk@axiros.com',
     description='Terminal Markdown Viewer',
