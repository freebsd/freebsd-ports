--- ./setup.py.orig	2014-07-28 22:22:14.902991707 +1000
+++ ./setup.py	2014-07-28 22:22:28.555883659 +1000
@@ -42,7 +42,7 @@
     url='http://fabfile.org',
     packages=find_packages(),
     test_suite='nose.collector',
-    tests_require=['nose', 'fudge<1.0'],
+    tests_require=['nose', 'fudge'],
     install_requires=install_requires,
     entry_points={
         'console_scripts': [
