--- ./setup.py.orig	2014-03-17 18:14:19.000000000 +0200
+++ ./setup.py	2014-03-17 18:14:54.000000000 +0200
@@ -23,13 +23,6 @@
     long_description=__doc__,
     zip_safe=False,
     install_requires=[],
-    tests_require=[
-        'django>=1',
-        'mock>=0.8.0',
-        'nose>=1.1.2',
-        'unittest2',
-    ],
-    test_suite='unittest2.collector',
     license='Apache License 2.0',
     include_package_data=True,
     classifiers=[
