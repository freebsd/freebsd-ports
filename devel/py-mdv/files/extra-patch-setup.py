--- setup.py.orig	2019-04-12 06:50:54 UTC
+++ setup.py
@@ -16,7 +16,7 @@ from setuptools import setup, find_packages
 
 version = "1.7.4"
 
-with open(os.path.join(os.path.dirname(__file__), "README.md")) as fd:
+with open(os.path.join(os.path.dirname(__file__), "README.md"), encoding='utf-8') as fd:
     md = fd.read()
 
 # images hack for pypi:
