--- setup.py.orig	2016-05-08 21:11:49 UTC
+++ setup.py
@@ -45,7 +45,7 @@ setup(
     url='http://fabfile.org',
     packages=find_packages(),
     test_suite='nose.collector',
-    tests_require=['nose<2.0', 'fudge<1.0', 'jinja2<3.0'],
+    tests_require=['nose', 'fudge', 'jinja2'],
     install_requires=install_requires,
     entry_points={
         'console_scripts': [
