--- setup.py.orig	2013-04-26 15:15:06.000000000 +0200
+++ setup.py	2013-04-26 15:16:48.000000000 +0200
@@ -31,5 +31,5 @@
         'Topic :: Software Development :: Libraries :: Python Modules'],
     long_description = "\n".join(pydot.__doc__.split('\n')),
     py_modules = ['pydot', 'dot_parser'],
-    install_requires = ['pyparsing', 'setuptools'],
-    data_files = [('.', ['LICENSE', 'README'])] )
+    install_requires = ['pyparsing', 'setuptools'] )
+    #data_files = [('.', ['LICENSE', 'README'])] )
