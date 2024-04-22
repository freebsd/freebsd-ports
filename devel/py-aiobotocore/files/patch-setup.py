--- setup.py.orig	2024-04-11 16:38:18 UTC
+++ setup.py
@@ -7,15 +7,15 @@ install_requires = [
 # NOTE: When updating botocore make sure to update awscli/boto3 versions below
 install_requires = [
     # pegged to also match items in `extras_require`
-    'botocore>=1.34.41,<1.34.70',
+    'botocore>=1.34.41',
     'aiohttp>=3.7.4.post0,<4.0.0',
     'wrapt>=1.10.10, <2.0.0',
     'aioitertools>=0.5.1,<1.0.0',
 ]
 
 extras_require = {
-    'awscli': ['awscli>=1.32.41,<1.32.70'],
-    'boto3': ['boto3>=1.34.41,<1.34.70'],
+    'awscli': ['awscli>=1.29.81'],
+    'boto3': ['boto3>=1.34.41'],
 }
 
 
