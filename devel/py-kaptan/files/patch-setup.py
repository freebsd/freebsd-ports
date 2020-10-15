--- setup.py.orig	2019-04-23 02:47:39 UTC
+++ setup.py
@@ -58,7 +58,7 @@ setup(
             'kaptan = kaptan:main',
         ],
     ),
-    classifiers=(
+    classifiers=[
         'Development Status :: 5 - Production/Stable',
         "Operating System :: POSIX",
         "Operating System :: MacOS :: MacOS X",
@@ -71,5 +71,5 @@ setup(
         'Programming Language :: Python :: 3.5',
         'Programming Language :: Python :: 3.6',
         'Programming Language :: Python :: 3.7',
-    ),
+    ],
 )
