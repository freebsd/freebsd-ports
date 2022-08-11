# 1) converters/py-rencode: Fails to configure if cython is installed
# 2) make setup.py test command work via test_suite directive
# 3) Honour/respect user CFLAGS
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=233561

--- setup.py.orig	2018-10-21 17:41:35 UTC
+++ setup.py
@@ -29,19 +29,14 @@ from distutils.errors import CCompilerError, Distutils
 from setuptools import setup
 from setuptools.extension import Extension
 
-try:
-    from Cython.Build import build_ext
-    from Cython.Build import cythonize
-except ImportError as ex:
-    from setuptools.command.build_ext import build_ext
-    cythonize = False
+from setuptools.command.build_ext import build_ext
+cythonize = False
 
 source_ext = ".pyx" if cythonize else ".c"
 
 ext_modules = [
     Extension(
         "rencode._rencode",
-        extra_compile_args=["-O3"],
         sources=["rencode/rencode" + source_ext],
     ),
 ]
@@ -92,5 +87,6 @@ setup(
   url="https://github.com/aresch/rencode",
   cmdclass={'build_ext': optional_build_ext},
   ext_modules=ext_modules,
-  setup_requires=['setuptools', 'wheel'],
+  setup_requires=['setuptools'],
+  test_suite='tests',
 )
