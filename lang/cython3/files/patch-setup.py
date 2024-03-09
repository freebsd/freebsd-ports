--- setup.py.orig	2024-01-10 09:54:48 UTC
+++ setup.py
@@ -243,7 +243,7 @@ def run_build():
 
     from Cython import __version__ as version
     setup(
-        name='Cython',
+        name='cython',
         version=version,
         url='https://cython.org/',
         author='Robert Bradshaw, Stefan Behnel, Dag Seljebotn, Greg Ewing, et al.',
