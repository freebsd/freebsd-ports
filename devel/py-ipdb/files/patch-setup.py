--- setup.py.orig	2015-06-03 09:21:14 UTC
+++ setup.py
@@ -48,7 +48,7 @@ setup(name='ipdb',
       license='GPL',
       packages=find_packages(exclude=['ez_setup', 'examples', 'tests']),
       include_package_data=True,
-      zip_safe=True,
+      zip_safe=False,
       test_suite='tests',
       install_requires=[
           'ipython >= 0.10',
