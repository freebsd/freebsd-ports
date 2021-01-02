--- setup.py.orig	2021-01-02 14:25:03 UTC
+++ setup.py
@@ -38,11 +38,4 @@ setup(
             'NanoVNASaver = NanoVNASaver.__main__:main'
         ],
     },
-    install_requires=[
-        'pyserial',
-        'PyQt5',
-        'numpy',
-        'scipy',
-        'cython',
-    ],
 )
