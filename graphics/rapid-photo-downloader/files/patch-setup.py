--- setup.py.orig	2020-12-24 23:41:26 UTC
+++ setup.py
@@ -271,7 +271,6 @@ setup(
         'scandir;python_version<"3.5"',
         'typing;python_version<"3.5"',
         'PyGObject',
-        'PyQt5',
         'babel',
     ],
     extras_require={
@@ -302,7 +301,7 @@ setup(
         )
     ],
     packages=['raphodo'],
-    python_requires='>=3.4.*, <4',
+    python_requires='>=3.4, <4',
     entry_points={
         'gui_scripts': ['rapid-photo-downloader=raphodo.rapid:main'],
         'console_scripts': ['analyze-pv-structure=raphodo.analyzephotos:main']
