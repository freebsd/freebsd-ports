--- setup.py.orig	2023-12-13 07:26:01 UTC
+++ setup.py
@@ -7,15 +7,15 @@ from setuptools import find_packages, setup
 # NOTE: When updating botocore make sure to update awscli/boto3 versions below
 install_requires = [
     # pegged to also match items in `extras_require`
-    'botocore>=1.33.2,<1.33.14',
+    'botocore>=1.33.2',
     'aiohttp>=3.7.4.post0,<4.0.0',
     'wrapt>=1.10.10, <2.0.0',
     'aioitertools>=0.5.1,<1.0.0',
 ]
 
 extras_require = {
-    'awscli': ['awscli>=1.31.2,<1.31.14'],
-    'boto3': ['boto3>=1.33.2,<1.33.14'],
+    'awscli': ['awscli>=1.29.81'],
+    'boto3': ['boto3>=1.33.2'],
 }
 
 
