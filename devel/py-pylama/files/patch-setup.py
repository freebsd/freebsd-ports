--- setup.py.orig	2019-08-17 21:11:41 UTC
+++ setup.py
@@ -35,7 +35,7 @@ meta = dict(
     author_email='horneds@gmail.com',
     url=' https://github.com/klen/pylama',
 
-    packages=find_packages(exclude=['plugins']),
+    packages=find_packages(exclude=['plugins', 'tests']),
 
     entry_points={
         'console_scripts': [
