
$FreeBSD$

--- setup.py.orig
+++ setup.py
@@ -1,6 +1,6 @@
 # bootstrap setuptools if necessary
-from ez_setup import use_setuptools
-use_setuptools()
+#from ez_setup import use_setuptools
+#use_setuptools()
 
 import kid as package
 
@@ -8,7 +8,8 @@
 package_version = package.__version__
 doc_parts = package.__doc__.strip().splitlines()
 
-from setuptools import setup
+#from setuptools import setup
+from distutils.core import setup
 setup(
     name=package_name,
     version=package_version,
@@ -25,7 +26,7 @@
     py_modules=[],
     packages=[package_name,
               package_name + '.test'],
-    install_requires=['elementtree'],
+    #install_requires=['elementtree'],
     classifiers = [
             'Development Status :: 4 - Beta',
             'Environment :: Console',
