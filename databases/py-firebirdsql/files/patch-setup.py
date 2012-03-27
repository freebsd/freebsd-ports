--- setup-old.py	2012-03-26 18:39:19.000000000 -0300
+++ setup.py	2012-03-26 18:40:01.000000000 -0300
@@ -10,10 +10,7 @@
     print(c)
 conn.close()
 """
-try:
-    from setuptools import setup
-except ImportError:
-    from distutils.core import setup
+from distutils.core import setup
 import firebirdsql
 
