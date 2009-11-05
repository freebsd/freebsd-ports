--- setup.py.orig	2009-11-05 22:41:45.000000000 +0800
+++ setup.py	2009-11-05 22:41:55.000000000 +0800
@@ -10,7 +10,7 @@
         'pyke.krb_compiler': ['*.krb'],
         'pyke.krb_compiler.ply': ['README', 'README.pyke'],
     },
-    data_files = [('pyke', ['LICENSE', 'README.txt'])],
+#    data_files = [('pyke', ['LICENSE', 'README.txt'])],
 
     # old setuptools stuff:
     #install_requires = [],
