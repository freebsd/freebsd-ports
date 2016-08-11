--- setup.py.orig	2016-05-24 01:57:52 UTC
+++ setup.py
@@ -27,5 +27,5 @@ setup(	name = 'pydot',
         'Topic :: Software Development :: Libraries :: Python Modules'],
     long_description = "\n".join(pydot.__doc__.split('\n')),
     py_modules = ['pydot', 'dot_parser'],
-    install_requires = ['pyparsing>=1.5.7'],
-    data_files = [('.', ['LICENSE', 'README'])] )
+    install_requires = ['pyparsing', 'setuptools'] )
+    #data_files = [('.', ['LICENSE', 'README'])] )
