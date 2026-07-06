--- setup.py.orig	2026-04-13 05:09:30 UTC
+++ setup.py
@@ -71,7 +71,7 @@ setup(
             '2k_earth_daymap.jpg',
         ],
     },
-    python_requires='>=3.7.*',
+    python_requires='>=3.7',
     install_requires=install_requires,
     extras_require={
         'all': ['matplotlib', 'colorcet', 'cmocean', 'meshio'],
