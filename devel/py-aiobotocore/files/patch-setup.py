--- setup.py.orig	2023-08-11 20:42:50 UTC
+++ setup.py
@@ -14,8 +14,8 @@ install_requires = [
 ]
 
 extras_require = {
-    'awscli': ['awscli>=1.29.17,<1.29.18'],
-    'boto3': ['boto3>=1.28.17,<1.28.18'],
+    'awscli': ['awscli>=1.29.17'],
+    'boto3': ['boto3>=1.28.17'],
 }
 
 
