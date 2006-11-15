--- setup.py.orig	Wed Aug 16 01:24:55 2006
+++ setup.py	Fri Nov 10 17:39:51 2006
@@ -2,11 +2,11 @@
 $URL: svn+ssh://svn.mems-exchange.org/repos/trunk/durus/setup.py $
 $Id: setup.py 28588 2006-08-15 17:11:08Z dbinger $
 """
-try:
-    import setuptools
-    used = setuptools # to quiet import checker.
-except ImportError:
-    pass
+# try:
+#     import setuptools
+#     used = setuptools # to quiet import checker.
+# except ImportError:
+#     pass
 
 import os
 from distutils.core import setup
