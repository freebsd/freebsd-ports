--- setup.py.orig	2013-12-13 12:37:02.344425745 -0200
+++ setup.py	2013-12-13 12:37:14.480426995 -0200
@@ -20,7 +20,7 @@
   packages=['gyp', 'gyp.generator'],
 
   scripts = ['gyp'],
-  cmdclass = {'install': install,
+  cmdclass = {
               'install_lib': install_lib,
               'install_scripts': install_scripts},
 )
