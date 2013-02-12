--- ./setup.py.orig	2013-01-23 18:34:56.000000000 +1100
+++ ./setup.py	2013-02-10 17:59:21.880891462 +1100
@@ -18,7 +18,7 @@
     long_description=open('README.markdown').read(),
     install_requires=[
         'pytz>=2010',
-        'python-dateutil>=1.5,<2.0',  # we're not compatible with python 3.0 yet
+        'python-dateutil>=1.5',  # py-dateutil >2.1 is Python 2/3 compat
         'unittest2'
     ],
     classifiers=[
@@ -54,6 +54,7 @@
     ],
     include_package_data=True,
     test_suite='sanetime.test',
-    platforms=['any']
+    platforms=['any'],
+    zip_safe=False
 )
 
