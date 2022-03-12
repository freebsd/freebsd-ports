--- setup.py.orig	2021-05-12 21:19:48 UTC
+++ setup.py
@@ -5,9 +5,28 @@ except ImporError:
     from setuptools import setup
 except ImporError:
     from distutils.core import setup
+from setuptools.command.test import test as TestCommand
 import os.path
 import sys
 
+class PyTest(TestCommand):
+    user_options = [('pytest-args=', 'a', "Arguments to pass to py.test")]
+
+    def initialize_options(self):
+        TestCommand.initialize_options(self)
+        self.pytest_args = []
+
+    def finalize_options(self):
+        TestCommand.finalize_options(self)
+        self.test_args = []
+        self.test_suite = True
+
+    def run_tests(self):
+        #import here, cause outside the eggs aren't loaded
+        import pytest
+        errno = pytest.main(self.pytest_args)
+        sys.exit(errno)
+
 # stop with the bug reports
 if sys.version_info < (2, 7):
     raise RuntimeError("Twiggy requires Python 2.7 or greater")
@@ -41,4 +60,6 @@ setup(name='Twiggy',
       "Programming Language :: Python :: 3.9",
       "License :: OSI Approved :: BSD License",],
       long_description=open('README.rst').read(),
+      tests_require=['pytest'],
+      cmdclass = {'test': PyTest},
       )
