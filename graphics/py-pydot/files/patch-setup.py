--- setup.py.orig	2008-07-06 15:01:26.000000000 +0200
+++ setup.py	2008-07-06 15:01:51.000000000 +0200
@@ -27,5 +27,5 @@
         'Topic :: Software Development :: Libraries :: Python Modules'],
     long_description = "\n".join(pydot.__doc__.split('\n')),
     py_modules = ['pydot', 'dot_parser'],
-    install_requires = ['pyparsing', 'setuptools'],
-    data_files = [('.', ['ChangeLog', 'LICENSE', 'README'])] )
+    install_requires = ['pyparsing', 'setuptools'] )
+    #data_files = [('.', ['ChangeLog', 'LICENSE', 'README'])]
