--- setup.py.orig	2014-05-27 07:33:54 UTC
+++ setup.py
@@ -74,8 +74,6 @@ if __name__ == '__main__':
     try:
         # http://peak.telecommunity.com/DevCenter/setuptools#basic-use
         from setuptools import setup
-        # distribute is probably installed, so use_2to3 should work
-        conf['use_2to3'] = True
     except ImportError:
         # http://docs.python.org/release/2.4.4/dist/setup-script.html
         from distutils.core import setup
