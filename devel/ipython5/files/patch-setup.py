# Release pygments because devel/ipython5 is python:3.5+ now.
# https://github.com/ipython/ipython/pull/12174
#
# This avoids some conflicts:
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=250074
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=250144
--- setup.py.orig	2020-05-01 18:12:21 UTC
+++ setup.py
@@ -182,7 +182,7 @@ extras_require = dict(
     parallel = ['ipyparallel'],
     qtconsole = ['qtconsole'],
     doc = ['Sphinx>=1.3'],
-    test = ['nose>=0.10.1', 'requests', 'testpath', 'pygments<2.6', 'nbformat', 'ipykernel'],
+    test = ['nose>=0.10.1', 'requests', 'testpath', 'pygments', 'nbformat', 'ipykernel'],
     terminal = [],
     kernel = ['ipykernel'],
     nbformat = ['nbformat'],
@@ -197,7 +197,7 @@ install_requires = [
     'simplegeneric>0.8',
     'traitlets>=4.2',
     'prompt_toolkit>=1.0.4,<2.0.0',
-    'pygments<2.6',
+    'pygments',
 ]
 
 # Platform-specific dependencies:
