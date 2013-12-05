--- ./setup.py.orig	2012-09-12 19:25:34.000000000 +1000
+++ ./setup.py	2013-12-05 21:21:46.941032294 +1100
@@ -1,17 +1,22 @@
 import os
+import sys
 from setuptools import setup
 
 install_requires = [
     'mysql-python>=1.2.3', 
     'psycopg2>=2.4.2',
     'pyyaml>=3.10.0',
-    'argparse',
     'pytz',
 ]
 
 if os.name == 'posix':
     install_requires.append('termcolor>=1.1.0')
-    
+
+version = sys.version_info[:2]
+
+if version < (2,7) or (3,0) <= version <= (3,1):
+    install_requires += ['argparse']
+
 setup(
     name='py-mysql2pgsql',
     version='0.1.6',
