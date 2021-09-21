--- setup.py.orig	2021-05-13 23:43:32 UTC
+++ setup.py
@@ -41,7 +41,7 @@ setup(
     long_description=open('README.rst').read(),
     install_requires=[
         'opencensus-context == 0.1.2',
-        'google-api-core >= 1.0.0, < 2.0.0',
+        'google-api-core >= 1.0.0, < 3.0.0',
     ],
     extras_require={},
     license='Apache-2.0',
