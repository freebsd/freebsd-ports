--- setup.py.orig	2016-07-16 18:17:04 UTC
+++ setup.py
@@ -6,11 +6,11 @@ from setuptools import setup, find_packa
 import awscli
 
 
-requires = ['botocore==1.4.37',
+requires = ['botocore>=1.4.37',
             'colorama>=0.2.5,<=0.3.7',
             'docutils>=0.10',
             'rsa>=3.1.2,<=3.5.0',
-            's3transfer==0.0.1']
+            's3transfer>=0.0.1']
 
 
 if sys.version_info[:2] == (2, 6):
