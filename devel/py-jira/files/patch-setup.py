--- setup.py.orig	2014-03-31 18:51:32.994913332 +0600
+++ setup.py	2014-03-31 18:51:50.178924965 +0600
@@ -8,11 +8,6 @@
     version=__version__,
     packages=find_packages(),
 
-    install_requires=['requests>=1.2.3',
-                      'requests_oauthlib>=0.3.3',
-                      'ipython>=0.13',
-                      'tlslite>=0.4.4'],
-    setup_requires=['sphinx', 'requests_oauthlib'],
     extras_require={
         'magic': ['filemagic>=1.6'],
     },
