--- setup.py.orig	2015-06-25 09:44:36 UTC
+++ setup.py
@@ -1,9 +1,28 @@
 #!/usr/bin/env python
 
+from setuptools.command.test import test as TestCommand
 from distutils.core import setup
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
 if sys.version_info < (2, 6):
     raise RuntimeError("Twiggy requires Python 2.6 or greater")
@@ -34,4 +53,6 @@ setup(name='Twiggy',
       "Programming Language :: Python :: 3.4",
       "License :: OSI Approved :: BSD License",],
       long_description=open('README.rst').read(),
+      tests_require=['pytest'],
+      cmdclass = {'test': PyTest},
       )
