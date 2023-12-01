--- setup.py.orig	2023-11-29 01:07:34 UTC
+++ setup.py
@@ -7,15 +7,15 @@ from setuptools import find_packages, setup
 # NOTE: When updating botocore make sure to update awscli/boto3 versions below
 install_requires = [
     # pegged to also match items in `extras_require`
-    'botocore>=1.32.4,<1.33.2',
+    'botocore>=1.32.4',
     'aiohttp>=3.7.4.post0,<4.0.0',
     'wrapt>=1.10.10, <2.0.0',
     'aioitertools>=0.5.1,<1.0.0',
 ]
 
 extras_require = {
-    'awscli': ['awscli>=1.30.4,<1.31.2'],
-    'boto3': ['boto3>=1.29.4,<1.33.2'],
+    'awscli': ['awscli>=1.30.4'],
+    'boto3': ['boto3>=1.29.4'],
 }
 
 
