--- setup.py.orig	2009-02-18 08:58:48.199458174 +0800
+++ setup.py	2009-02-18 08:58:56.569760265 +0800
@@ -5,7 +5,7 @@
 if sys.version_info < (2, 3):
   raise Error, "Python 2.3 or later is required"
 
-include_dirs = []
+include_dirs = ['/usr/local/include']
 library_dirs = ['/usr/local/lib']
 
 if sys.platform == 'darwin':
