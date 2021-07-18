--- setup.py.orig	2020-03-09 17:39:51 UTC
+++ setup.py
@@ -7,7 +7,7 @@ import setuptools
 if platform.python_implementation() == 'PyPy':
     install_requires = ['psycopg2cffi>=2.7.2,<2.9']
 else:
-    install_requires = ['psycopg2>=2.5.1,<2.9']
+    install_requires = ['psycopg2>=2.5.1,<3']
 
 # Install tornado if generating docs on readthedocs
 if os.environ.get('READTHEDOCS', None) == 'True':
