--- setup.py.orig	2015-12-08 03:19:32 UTC
+++ setup.py
@@ -11,7 +11,5 @@ setup(
     license='MIT',
     packages=['pkgconfig'],
     description="Interface Python with pkg-config",
-    long_description=open('README.rst').read(),
-    setup_requires=['nose>=1.0'],
-    test_suite='test',
+    long_description=open('README.rst').read()
 )
