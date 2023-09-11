--- setup.py.orig	2023-01-31 18:28:24 UTC
+++ setup.py
@@ -10,10 +10,8 @@ except ImportError:
     extra = {'scripts': ["bin/pyflakes"]}
 else:
     extra = {
+        'scripts': ["bin/pyflakes"],
         'test_suite': 'pyflakes.test',
-        'entry_points': {
-            'console_scripts': ['pyflakes = pyflakes.api:main'],
-        },
     }
 
 
