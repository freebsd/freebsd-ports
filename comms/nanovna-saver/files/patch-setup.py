--- setup.py.orig	2020-08-13 17:01:29 UTC
+++ setup.py
@@ -37,12 +37,5 @@ setup(
         'console_scripts': [
             'NanoVNASaver = NanoVNASaver.__main__:main'
         ],
-    },
-    install_requires=[
-        'pyserial',
-        'PyQt5',
-        'numpy',
-        'scipy<1.5',
-        'cython',
-    ],
+    }
 )
