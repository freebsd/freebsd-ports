--- setup.py.orig	2019-12-03 11:30:30 UTC
+++ setup.py
@@ -46,7 +46,7 @@ setup(name='ipdb',
       license='BSD',
       packages=find_packages(exclude=['ez_setup', 'examples', 'tests']),
       include_package_data=True,
-      zip_safe=True,
+      zip_safe=False,
       test_suite='tests',
       python_requires=">=2.7",
       install_requires=[
