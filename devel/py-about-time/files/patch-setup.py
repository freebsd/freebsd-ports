--- setup.py.orig	2022-12-21 04:14:53 UTC
+++ setup.py
@@ -53,7 +53,6 @@ setup(
     ],
     keywords='python track tracker time code blocks monitor statistics analytics'.split(),
     packages=find_packages(),
-    data_files=[('', ['LICENSE'])],
     python_requires='>=3.7, <4',
     install_requires=[],
 )
