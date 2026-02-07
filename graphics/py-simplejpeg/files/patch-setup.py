--- setup.py.orig	2024-09-17 09:48:31 UTC
+++ setup.py
@@ -8,7 +8,6 @@ import subprocess
 import sysconfig
 import subprocess
 
-from cmake import CMAKE_BIN_DIR
 from setuptools import setup
 from setuptools import find_packages
 from setuptools import Extension
@@ -82,7 +81,7 @@ def make_type():
 
 
 def make_type():
-    if OS in ('linux', 'darwin'):
+    if OS in ('linux', 'darwin', 'freebsd'):
         return 'Unix Makefiles'
     elif OS == 'windows':
         return 'NMake Makefiles'
@@ -152,7 +151,7 @@ class cmake_build_ext(build_ext):
         os.chdir(build_dir)
         config = 'Debug' if self.debug else 'Release'
         env = dict(os.environ, **(env or {}))
-        cmake = pt.join(CMAKE_BIN_DIR, 'cmake')
+        cmake = 'cmake'
         subprocess.check_call([
             cmake,
             '-G' + make_type(), '-Wno-dev',
@@ -172,7 +171,7 @@ def _staticlib():
 
 
 def _staticlib():
-    if OS in ('linux', 'darwin'):
+    if OS in ('linux', 'darwin', 'freebsd'):
         return 'libturbojpeg.a'
     elif OS == 'windows':
         return 'turbojpeg-static.lib'
