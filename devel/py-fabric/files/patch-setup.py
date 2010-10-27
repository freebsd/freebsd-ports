--- setup.py.orig	2010-10-14 13:37:04.963787042 +0800
+++ setup.py	2010-10-14 13:37:11.377290180 +0800
@@ -31,7 +31,6 @@
     packages=find_packages(),
     test_suite='nose.collector',
     tests_require=['nose', 'fudge'],
-    install_requires=['pycrypto <2.1', 'paramiko >=1.7.6'],
     entry_points={
         'console_scripts': [
             'fab = fabric.main:main',
