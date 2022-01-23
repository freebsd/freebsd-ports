--- setup.py.orig	2021-03-30 03:56:45 UTC
+++ setup.py
@@ -66,7 +66,7 @@ setup(
     install_requires=[
         'pandas >= 0.15.0',
         'tables >=3.1, <3.6; python_version <"3.6"',
-        'tables >=3.1, <3.7; python_version >="3.6"',
+        'tables >=3.1, <3.8; python_version >="3.6"',
         'toolz >= 0.8.1'
     ],
     extras_require={
