--- ./setup.py.orig	2012-08-10 08:48:07.000000000 +1000
+++ ./setup.py	2012-08-15 22:27:30.000000000 +1000
@@ -3,10 +3,7 @@
 
 from redis import __version__
 
-try:
-    from setuptools import setup
-except ImportError:
-    from distutils.core import setup
+from setuptools import setup
 
 f = open(os.path.join(os.path.dirname(__file__), 'README.md'))
 long_description = f.read()
@@ -41,5 +38,6 @@
         'Programming Language :: Python :: 3',
         'Programming Language :: Python :: 3.2',
         'Programming Language :: Python :: 3.3',
-        ]
+        ],
+    zip_safe=False,
 )
