https://bitbucket.org/pytest-dev/pytest-timeout/pull-requests/15/use-utf-8-encoding-to-open-the-readme-file/

--- setup.py.orig	2018-08-02 04:04:34 UTC
+++ setup.py
@@ -1,10 +1,11 @@
 from setuptools import setup
+import io
 
 
 setup(
     name='pytest-timeout',
     description='py.test plugin to abort hanging tests',
-    long_description=open("README").read(),
+    long_description=io.open('README', encoding='utf-8').read(),
     version='1.3.1',
     author='Floris Bruynooghe',
     author_email='flub@devork.be',
