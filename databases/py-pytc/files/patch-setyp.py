--- setup.py.orig	2009-06-12 02:49:50.405623403 +0800
+++ setup.py	2009-06-12 02:50:50.873879838 +0800
@@ -8,8 +8,8 @@
 if sys.version_info < (2, 3):
   raise Error, "Python 2.3 or later is required"
 
-include_dirs = []
-library_dirs = ['/usr/local/lib']
+include_dirs = ['%%LOCALBASE%%/include']
+library_dirs = ['%%LOCALBASE%%/lib']
 
 if sys.platform == 'linux2':
   os.environ['PATH'] += ":/usr/local/bin:$home/bin:.:..:../.."
