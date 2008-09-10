--- setup.py.orig	2008-02-15 04:48:02.000000000 +0800
+++ setup.py	2008-09-10 11:12:00.000000000 +0800
@@ -1,9 +1,9 @@
 #!/usr/bin/env python
 
-try:
-    from setuptools import setup
-except ImportError, excp:
-    from distutils.core import setup
+#try:
+#    from setuptools import setup
+#except ImportError, excp:
+from distutils.core import setup
     
 import pydot
 
@@ -27,5 +27,5 @@
         'Topic :: Software Development :: Libraries :: Python Modules'],
     long_description = "\n".join(pydot.__doc__.split('\n')),
     py_modules = ['pydot', 'dot_parser'],
-    install_requires = ['pyparsing', 'setuptools'],
-    data_files = [('.', ['ChangeLog', 'LICENSE', 'README'])] )
+    install_requires = ['pyparsing', 'setuptools'] )
+    #data_files = [('.', ['ChangeLog', 'LICENSE', 'README'])]
