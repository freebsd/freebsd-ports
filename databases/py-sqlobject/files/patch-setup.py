--- setup.py.orig	Fri Oct 21 15:43:47 2005
+++ setup.py	Fri Oct 21 15:44:13 2005
@@ -1,11 +1,11 @@
 # ez_setup doesn't work with Python 2.2, so we use distutils
 # in that case:
-try:
-    from ez_setup import use_setuptools
-    use_setuptools()
-    from setuptools import setup
-except ImportError:
-    from distutils.core import setup
+# try:
+#     from ez_setup import use_setuptools
+#     use_setuptools()
+#     from setuptools import setup
+# except ImportError:
+from distutils.core import setup
 
 subpackages = ['firebird', 'inheritance', 'mysql', 'postgres',
                'sqlite', 'sybase', 'maxdb', 'util', 'manager']
