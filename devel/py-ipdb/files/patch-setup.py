--- setup.py.orig	2013-06-12 23:11:21.000000000 -0700
+++ setup.py	2013-06-12 23:11:32.000000000 -0700
@@ -41,7 +41,7 @@
       license='GPL',
       packages=find_packages(exclude=['ez_setup', 'examples', 'tests']),
       include_package_data=True,
-      zip_safe=True,
+      zip_safe=False,
       test_suite='tests',
       install_requires=[
           'ipython >= 0.10',
