--- setup.py.orig	2012-01-03 00:15:07 UTC
+++ setup.py
@@ -2,7 +2,7 @@
 
 try:
     from distutils.core import setup
-except ImportError, excp:
+except ImportError as excp:
     from setuptools import setup
     
 import pydot
@@ -31,5 +31,5 @@ setup(	name = 'pydot',
         'Topic :: Software Development :: Libraries :: Python Modules'],
     long_description = "\n".join(pydot.__doc__.split('\n')),
     py_modules = ['pydot', 'dot_parser'],
-    install_requires = ['pyparsing', 'setuptools'],
-    data_files = [('.', ['LICENSE', 'README'])] )
+    install_requires = ['pyparsing', 'setuptools'] )
+    #data_files = [('.', ['LICENSE', 'README'])] )
