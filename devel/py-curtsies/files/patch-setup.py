--- setup.py.orig	2018-02-13 22:54:06 UTC
+++ setup.py
@@ -41,7 +41,7 @@ setup(name='curtsies',
       install_requires = [
           'blessings>=1.5',
           'wcwidth>=0.1.4',
-          'typing',
+          'typing; python_version<"3.5"',
       ],
       tests_require = [
           'mock',
