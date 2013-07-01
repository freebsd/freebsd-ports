--- setup.py.bak	2013-07-01 15:04:58.000000000 +0400
+++ setup.py	2013-07-01 15:05:14.000000000 +0400
@@ -22,9 +22,4 @@
     zip_safe=False,
     packages=find_packages('src'),
     include_package_data=True,
-    package_dir={'': 'src'},
-    install_requires=[
-        'pytest',
-        'pytest-capturelog',
-        'pytest-codecheckers',
-        'pytest-cov'])
+    package_dir={'': 'src'},)
