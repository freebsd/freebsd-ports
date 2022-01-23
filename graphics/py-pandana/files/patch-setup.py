--- setup.py.orig	2021-03-17 16:44:15 UTC
+++ setup.py
@@ -151,7 +151,7 @@ setup(
         'requests >=2.0',
         'scikit-learn >=0.18',
         'tables >=3.1, <3.6; python_version <"3.6"',
-        'tables >=3.1, <3.7; python_version >="3.6"'
+        'tables >=3.1, <3.8; python_version >="3.6"'
     ],
     cmdclass={
         'test': PyTest,
