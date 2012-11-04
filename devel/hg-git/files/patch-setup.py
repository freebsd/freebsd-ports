--- ./setup.py.orig	2012-11-01 15:10:46.000000000 +0100
+++ ./setup.py	2012-11-03 10:28:03.799021557 +0100
@@ -1,7 +1,4 @@
-try:
-    from setuptools import setup
-except:
-    from distutils.core import setup
+from distutils.core import setup
 
 setup(
     name='hg-git',
@@ -20,5 +17,4 @@
     license='GPLv2',
     packages=['hggit'],
     package_data={ 'hggit': ['help/git.rst'] },
-    install_requires=['dulwich>=0.8.0'],
 )
