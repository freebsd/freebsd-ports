--- ./setup.py.orig     2010-03-03 16:33:52.000000000 +0100
+++ ./setup.py  2010-03-03 21:13:31.000000000 +0100
@@ -3,8 +3,5 @@
 # Copyright (C) 2008-2010 Jelmer Vernooij <jelmer@samba.org>

-try:
-    from setuptools import setup, Extension
-except ImportError:
-    from distutils.core import setup, Extension
+from distutils.core import setup, Extension
 from distutils.core import Distribution

