--- ./setup.py.orig	2013-03-24 22:35:51.000000000 +0100
+++ ./setup.py	2013-03-30 13:51:43.535271164 +0100
@@ -1,13 +1,5 @@
-try:
-    from setuptools import setup
-except:
-    from distutils.core import setup
-
-try:
-    from collections import OrderedDict
-    extra_req = []
-except ImportError:
-    extra_req = ['ordereddict>=1.1']
+from distutils.core import setup
+from collections import OrderedDict
 
 setup(
     name='hg-git',
@@ -26,5 +18,4 @@
     license='GPLv2',
     packages=['hggit'],
     package_data={ 'hggit': ['help/git.rst'] },
-    install_requires=['dulwich>=0.8.6'] + extra_req,
 )
