--- setup.py.orig	2021-02-24 08:56:12 UTC
+++ setup.py
@@ -24,12 +24,12 @@ setup(
         "Programming Language :: Python :: 3.6",
     ],
     install_requires=[
-        'grpcio==1.18.0',
-        'grpcio-tools==1.18.0',
-        'colorama==0.3.3',
-        'termcolor==1.1.0',
-        'tqdm==4.31.1',
-        'bleach==2.1.0'
+        'grpcio>=1.18.0',
+        'grpcio-tools>=1.18.0',
+        'colorama>=0.3.3',
+        'termcolor>=1.1.0',
+        'tqdm>=4.31.1',
+        'bleach>=2.1.0'
     ],
     entry_points={
         'console_scripts': [
