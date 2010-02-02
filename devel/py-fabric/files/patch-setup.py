
$FreeBSD$

--- setup.py.orig
+++ setup.py
@@ -16,7 +16,6 @@
     author_email='jeff@bitprophet.org',
     url='http://fabfile.org',
     packages=find_packages(),
-    install_requires=['pycrypto >=1.9'],
     entry_points={
         'console_scripts': [
             'fab = fabric.main:main',
