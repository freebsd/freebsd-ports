--- setup.py.orig	2011-05-23 16:20:40.000000000 +0800
+++ setup.py	2011-05-23 16:21:33.000000000 +0800
@@ -37,7 +37,6 @@
     packages=find_packages(),
     test_suite='nose.collector',
     tests_require=['nose', 'fudge'],
-    install_requires=['pycrypto >= 1.9', 'paramiko >=1.7.6'],
     entry_points={
         'console_scripts': [
             'fab = fabric.main:main',
