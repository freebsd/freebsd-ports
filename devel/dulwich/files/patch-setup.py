--- ./setup.py.orig     2010-01-03 19:09:07.000000000 +0100
+++ ./setup.py  2010-01-03 19:09:19.000000000 +0100
@@ -2,10 +2,7 @@
 # Setup file for bzr-git
 # Copyright (C) 2008-2009 Jelmer Vernooij <jelmer@samba.org>

-try:
-    from setuptools import setup
-except ImportError:
-    from distutils.core import setup
+from distutils.core import setup
 from distutils.extension import Extension

 dulwich_version_string = '0.4.1'

