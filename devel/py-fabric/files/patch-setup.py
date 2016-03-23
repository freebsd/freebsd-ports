--- setup.py.orig	2016-03-03 08:01:28 UTC
+++ setup.py
@@ -45,7 +45,7 @@ setup(
     url='http://fabfile.org',
     packages=find_packages(),
     test_suite='nose.collector',
-    tests_require=['nose', 'fudge<1.0', 'jinja2'],
+    tests_require=['nose', 'fudge', 'jinja2'],
     install_requires=install_requires,
     entry_points={
         'console_scripts': [
