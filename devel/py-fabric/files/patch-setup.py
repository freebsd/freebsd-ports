--- setup.py.orig	2010-11-13 04:57:34.000000000 +0800
+++ setup.py	2011-01-20 12:46:01.754034224 +0800
@@ -38,7 +38,6 @@
     packages=find_packages(),
     test_suite='nose.collector',
     tests_require=['nose', 'fudge'],
-    install_requires=['pycrypto %s' % PYCRYPTO, 'paramiko >=1.7.6'],
     entry_points={
         'console_scripts': [
             'fab = fabric.main:main',
